const handler = require('serve-handler');
const http = require('http');

const server = http.createServer((request, response) => {
  response.setHeader('Cross-Origin-Embedder-Policy', 'require-corp')
  response.setHeader('Cross-Origin-Opener-Policy', 'same-origin')
  return handler(request, response);
});

server.listen(3000, () => {
  console.log('Running at http://localhost:3000');
});
