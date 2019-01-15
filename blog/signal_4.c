#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void sighandler(int sig) {
  switch(sig) {
    case SIGUSR1:
      printf("hello SIGUSR1\n");break;
    case SIGUSR2:
      printf("hello SIGUSR2\n");break;
    case SIGINT:
      printf("休想干掉我！\n");break;
    case SIGTSTP:
      printf("不要停止我！\n");break;
    case SIGQUIT:
      printf("就是不退出！\n");break;
    case SIGSEGV:
      printf("呃！程序出 bug 了！\n");break;
    default:
      printf("hello, who are you %d?\n", sig);
  }
  sleep(2); // 删除这一行，再给程序发信号，看看 main 函数打点的情况。
}


int main() {
  printf("I'm %d\n", getpid());

  if (SIG_ERR == signal(SIGUSR1, sighandler)) {
    perror("signal SIGUSR1");
  }
  if (SIG_ERR == signal(SIGUSR2, sighandler)) {
    perror("signal SIGUSR2");
  }
  if (SIG_ERR == signal(SIGINT, sighandler)) {
    perror("signal SIGINT");
  }
  if (SIG_ERR == signal(SIGTSTP, sighandler)) {
    perror("signal SIGTSTP");
  }
  if (SIG_ERR == signal(SIGQUIT, sighandler)) {
    perror("signal SIGQUTI");
  }
  if (SIG_ERR == signal(SIGSEGV, sighandler)) {
    perror("signal SIGSEGV");
  }

  while(1) {
    write(STDOUT_FILENO, ".", 1); 
    sleep(10);
  }   
  return 0;
}

