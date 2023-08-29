```
npm install
docker build . -t testwasm
docker rm testwasm
docker create --name=testwasm testwasm:latest
docker cp testwasm:/src/index.html .
docker cp testwasm:/src/index.js .
docker cp testwasm:/src/index.wasm .
docker cp testwasm:/src/index.worker.js .                                            │
node index.js
```
