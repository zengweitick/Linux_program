#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<wait.h>
#include<stdlib.h>
int main(){
 pid_t pid;
 int ret;
 pid=fork();
 if(pid<0){
   perror("fork");
   exit(1);
 }
 else if(pid==0){
	 printf("Hello I am child[%d]\n",getpid());
    raise(SIGSTOP);
	exit(0);
 }
 else{
	 sleep(2);
    printf("子进程的进程号是:[%d]\n",pid);
	if((waitpid(pid,NULL,WNOHANG))==0){
          if(ret=(kill(pid,SIGKILL)==0))printf("用kill函数返回值：%d发送SIGKILL信号结束的进程是：%d\n",ret,pid);
		  else{perror("failed!\n");}

 }
}
return 0;
}
