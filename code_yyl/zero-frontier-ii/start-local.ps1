param([switch]$NoBrowser, [switch]$NoPause)
$ErrorActionPreference = 'Stop'
$ProgressPreference = 'SilentlyContinue'

$gameRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
$serverPath = (Resolve-Path -LiteralPath (Join-Path $gameRoot 'serve.cjs')).Path
$runtimePath = Join-Path $gameRoot 'runtime'
$pidPath = Join-Path $runtimePath 'server.pid'
$gameUrl = 'http://127.0.0.1:4174/'

function Test-ThisServer([int]$candidateId) {
    if ($candidateId -le 0) { return $false }
    try {
        $candidate = Get-CimInstance Win32_Process -Filter "ProcessId = $candidateId" -ErrorAction Stop
        $pattern = '(?i)(^|[\s"])' + [regex]::Escape($serverPath) + '(?=[\s"]|$)'
        return ($null -ne $candidate -and $candidate.Name -ieq 'node.exe' -and $candidate.CommandLine -match $pattern)
    } catch { return $false }
}

try {
    New-Item -ItemType Directory -Force -Path $runtimePath | Out-Null
    if (Test-Path -LiteralPath $pidPath -PathType Leaf) {
        $existingId = 0
        [int]::TryParse((Get-Content -LiteralPath $pidPath -Raw).Trim(), [ref]$existingId) | Out-Null
        if (Test-ThisServer $existingId) {
            try {
                $response = Invoke-WebRequest -Uri $gameUrl -TimeoutSec 2 -UseBasicParsing
                if ($response.StatusCode -eq 200 -and $response.Content.Contains('ZERO FRONTIER')) {
                    Write-Host '游戏已在运行，正在打开页面。'
                    if (-not $NoBrowser) { Start-Process -FilePath $gameUrl }
                    exit 0
                }
            } catch { }
        }
        Remove-Item -LiteralPath $pidPath -Force -ErrorAction SilentlyContinue
    }

    $node = Get-Command node -CommandType Application -ErrorAction SilentlyContinue | Select-Object -First 1
    if (-not $node) { throw '未找到 Node.js。请先安装 Node.js，再双击“启动游戏.cmd”。' }
    $portOccupied = $false
    try { Invoke-WebRequest -Uri $gameUrl -TimeoutSec 1 -UseBasicParsing | Out-Null; $portOccupied = $true } catch { }
    if ($portOccupied) { throw '端口 4174 已被其他程序使用。请关闭占用该端口的程序后重试。' }

    $stdout = Join-Path $runtimePath 'server.log'
    $stderr = Join-Path $runtimePath 'server-error.log'
    $oldPort = $env:PORT
    try {
        $env:PORT = '4174'
        $server = Start-Process -FilePath $node.Source -ArgumentList ('"' + $serverPath + '"') -WorkingDirectory $gameRoot -WindowStyle Hidden -RedirectStandardOutput $stdout -RedirectStandardError $stderr -PassThru
    } finally { $env:PORT = $oldPort }
    [IO.File]::WriteAllText($pidPath, [string]$server.Id, [Text.Encoding]::ASCII)

    for ($attempt = 0; $attempt -lt 40; $attempt++) {
        $server.Refresh()
        if ($server.HasExited) { throw '游戏服务启动失败。请查看 runtime/server-error.log。' }
        try {
            $response = Invoke-WebRequest -Uri $gameUrl -TimeoutSec 1 -UseBasicParsing
            if ($response.StatusCode -eq 200 -and $response.Content.Contains('ZERO FRONTIER')) {
                Write-Host '游戏已启动：http://127.0.0.1:4174/'
                if (-not $NoBrowser) { Start-Process -FilePath $gameUrl }
                exit 0
            }
        } catch { }
        Start-Sleep -Milliseconds 200
    }
    throw '游戏启动超时。请查看 runtime 文件夹中的日志。'
} catch {
    Write-Host ('启动失败：' + $_.Exception.Message) -ForegroundColor Red
    if (-not $NoPause) { Read-Host '按回车键关闭窗口' | Out-Null }
    exit 1
}
