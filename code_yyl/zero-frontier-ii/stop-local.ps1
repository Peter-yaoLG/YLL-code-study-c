param([switch]$NoPause)
$ErrorActionPreference = 'Stop'
$gameRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
$serverPath = (Resolve-Path -LiteralPath (Join-Path $gameRoot 'serve.cjs')).Path
$pidPath = Join-Path (Join-Path $gameRoot 'runtime') 'server.pid'

try {
    if (-not (Test-Path -LiteralPath $pidPath -PathType Leaf)) { Write-Host '本目录的游戏服务没有运行。'; exit 0 }
    $processId = 0
    [int]::TryParse((Get-Content -LiteralPath $pidPath -Raw).Trim(), [ref]$processId) | Out-Null
    if ($processId -le 0) { Remove-Item -LiteralPath $pidPath -Force; Write-Host '已清除失效的服务记录。'; exit 0 }
    $candidate = Get-CimInstance Win32_Process -Filter "ProcessId = $processId" -ErrorAction Stop
    if ($null -eq $candidate) { Remove-Item -LiteralPath $pidPath -Force; Write-Host '游戏服务已经停止。'; exit 0 }
    $pattern = '(?i)(^|[\s"])' + [regex]::Escape($serverPath) + '(?=[\s"]|$)'
    if ($candidate.Name -ine 'node.exe' -or $candidate.CommandLine -notmatch $pattern) {
        throw '记录的进程不属于本目录的游戏服务，已拒绝停止，以免影响其他程序。'
    }
    Stop-Process -Id $processId -ErrorAction Stop
    Wait-Process -Id $processId -Timeout 5 -ErrorAction SilentlyContinue
    Remove-Item -LiteralPath $pidPath -Force -ErrorAction SilentlyContinue
    Write-Host '本目录的游戏服务已停止。'
} catch {
    Write-Host ('停止失败：' + $_.Exception.Message) -ForegroundColor Red
    if (-not $NoPause) { Read-Host '按回车键关闭窗口' | Out-Null }
    exit 1
}
