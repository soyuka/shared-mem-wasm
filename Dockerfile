FROM emscripten/emsdk:3.1.45 as build_tool

COPY test.c .
ENV EMCC_CFLAGS "-pthread -sSHARED_MEMORY"
RUN emcc test.c -o index.html
