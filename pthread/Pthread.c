#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
   pid_t pid;
   pid=fork();
   if(pid<0){
     printf("pthread failed\n");
	 return 1;
   }
   else if(pid==0){
    printf("this is child");
    printf("the parent pid: %d,child pid:%d",getppid(),getpid());
    exit(9);
   }
  else{

   printf("this is parent\n");
   sleep(300);
   wait(NULL);
  return 0;

  }

}
