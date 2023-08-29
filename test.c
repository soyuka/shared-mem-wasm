#include <sys/types.h>
#include <stdio.h>
#include <emscripten.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

#ifndef MAP_ANON
# ifdef MAP_ANONYMOUS
#  define MAP_ANON MAP_ANONYMOUS
# endif
#endif
#ifndef MAP_FAILED
# define MAP_FAILED ((void*)-1)
#endif

int main(void) {
  pid_t pid;
  int status;
  char *shm;

  shm = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);
  if (shm == MAP_FAILED) {
    printf("1\n");
    return 1;
  }

  strcpy(shm, "hello");

  pid = fork();
  if (pid < 0) {
    printf("5\n");
    return 5;
  } else if (pid == 0) {
    printf("6\n");
    strcpy(shm, "bye");
    return 6;
  }
  if (wait(&status) != pid) {
    printf("7\n");
    return 7;
  }
  if (!WIFEXITED(status) || WEXITSTATUS(status) != 6) {
    printf("8\n");
    return 8;
  }
  if (strcmp(shm, "bye") != 0) {
    printf("9\n");
    return 9;
  }

	printf("ok\n");
  return 0;
}
