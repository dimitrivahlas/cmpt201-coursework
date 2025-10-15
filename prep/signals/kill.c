#define _POSIX_C_SOURCE 200809
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static char *m = "CCTRL C pressed \n";
void handler(int signum) { write(STDOUT_FILENO, m, strlen(m)); }

int main() {
  struct sigaction a;
  a.sa_handler = handler;
  a.sa_flags = 0;
  sigemptyset(&a.sa_mask);

  // register signal handler
  int ret = sigaction(SIGINT, &a, NULL);
  if (ret == -1) {
    perror("SIGACTION FIALED \n");
    exit(EXIT_FAILURE);
  }
  while (true) {
    sleep(1);
  }
}
