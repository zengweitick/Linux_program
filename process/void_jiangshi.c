#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
  pid_t pid,wpid;
  int status,i;
  pid=fork();
  if(pid==0){
    printf("这是子进程,进程好为：%d\n",getpid());
	sleep(5);
	exit(6);
  }
  else {
    printf("这是父进程，正在等待子进程....\n");
	wpid=wait(&status);
	i=WEXITSTATUS(status);
	printf("等待的进程的进程号（pid）是：%d,结束状态:%d\n",wpid,i);
  }
}
