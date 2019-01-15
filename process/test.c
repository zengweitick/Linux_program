#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
  int pid, i;
  int group1, group2;

  setpgid(getpid(), getpid());
  group1 = getpgid(getpid());
 for (i = 0; i < 3; ++i) {
    pid = fork();
    if (pid > 0) {
      // father
      if (i == 0) {
        setpgid(pid, pid);
        group2 = getpgid(pid);
      }   
      else if (i == 1) {
        setpgid(pid, group1);
      }   
      else if (i == 2) {
        setpgid(pid, group2);
      }   
      break;
    }   
  else if (pid == 0) {
      // child
      if (i == 0) {
        setpgid(getpid(), getpid());
        group2 = getpgid(getpid());
      }   
      else if (i == 1) {
        setpgid(getpid(), group1);
      }   
      else if (i == 2) {
        setpgid(getpid(), group2);
      }   
    }   
    else if (pid < 0) {
      perror("fork");
      return -1; 
    }   
  }

  printf("进程 %d, pid: %d -> ppid: %d, pgid: [%d], (%s)\n", i, getpid(), getppid(), getpgid(getpid()), strerror(errno));
  while(1) sleep(1);
  return 0;
}
 
 
