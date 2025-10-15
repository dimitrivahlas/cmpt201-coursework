#define _POSIX_C_SOURCE 200809
#include <signal.h>

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

static char *m = "Ctrl-c pressed \n";
void handle_sigint(int signum) { write(STDOUT_FILENO, m, strlen(m)); }

int main() {
  struct sigaction act;
  act.sa_handler = handle_sigint;
  act.sa_flags = 0;
  sigemptyset(&act.sa_mask);

  int ret = sigaction(SIGINT, &act, NULL);
  if (ret == -1) {
    perror("Sigacrtion failed");
    exit(EXIT_FAILURE);
  }

  while (true) {
    sleep(1);
  }
}
