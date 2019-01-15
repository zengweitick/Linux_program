#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <wait.h>
#include <stdio.h>
#include <stdlib.h>
void handler(int sig) {
  if (sig == SIGUSR1) {
    printf("Hello my child\n");
  }
  else if (sig == SIGCHLD) {
    wait(NULL);
  }
}

void child() {
  int n = 10; 
  while(n--) {
    if (kill(getppid(), SIGUSR1) == -1) {
      perror("kill");
    }   
    sleep(1);
  }

  exit(0);
}

int main() {
  if (SIG_ERR == signal(SIGUSR1, handler)) {
    perror("signal SIGUSR1");
  }
  if (SIG_ERR== signal(SIGCHLD, handler)) {
    perror("signal SIGUSR2");
  }

  pid_t pid = fork();

  if (pid == 0) child();
  else if (pid == -1) {
    perror("fork");
  }

  while(1) {
    write(STDOUT_FILENO, ".", 1); 
    sleep(10);
  }

  return 0;
}
