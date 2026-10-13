'use strict';
const http = require('node:http');
const fs = require('node:fs');
const path = require('node:path');

const host = '127.0.0.1';
const port = Number(process.env.PORT || 4173);
if (!Number.isInteger(port) || port < 1 || port > 65535) throw new Error('Invalid PORT');
const files = new Map([
  ['/', ['index.html', 'text/html; charset=utf-8']],
  ['/index.html', ['index.html', 'text/html; charset=utf-8']],
  ['/style.css', ['style.css', 'text/css; charset=utf-8']],
  ['/game.js', ['game.js', 'text/javascript; charset=utf-8']]
]);
const server = http.createServer(async (req, res) => {
  const headers = {'Cache-Control':'no-store', 'X-Content-Type-Options':'nosniff', 'Referrer-Policy':'no-referrer'};
  const head = req.method === 'HEAD';
  if (req.method !== 'GET' && !head) { res.writeHead(405, {...headers, Allow:'GET, HEAD'}); res.end(); return; }
  if (!new RegExp('^(127\\.0\\.0\\.1|localhost):' + port + '$', 'i').test(req.headers.host || '')) { res.writeHead(421, headers); res.end(); return; }
  const file = files.get((req.url || '/').split('?')[0]);
  if (!file) { res.writeHead(404, headers); res.end(); return; }
  try {
    const data = await fs.promises.readFile(path.join(__dirname, file[0]));
    res.writeHead(200, {...headers, 'Content-Type':file[1], 'Content-Length':data.length});
    res.end(head ? undefined : data);
  } catch { res.writeHead(500, headers); res.end('Unable to load game file.'); }
});
server.on('error', error => {
  console.error(error.code === 'EADDRINUSE' ? 'Port is already in use. Choose another PORT or stop the existing server.' : 'Unable to start the game server.');
  process.exitCode = 1;
});
server.listen(port, host, () => console.log(`Game ready: http://${host}:${port}/`));
