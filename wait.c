#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
   pid_t pid,wpid;
   int status,i;
   pid=fork();
   if(pid==0){
      printf("This is child process pid=%d\n",getpid());
      sleep(5);
	  exit(100);
   }
  else{
    printf("this is parent process and pid=%d\n",getpid());
	wpid=wait(&status);
	i=WEXITSTATUS(status);
    printf("wait for process :%d,and the overstatus:%d\n",wpid,i);
  }

}
