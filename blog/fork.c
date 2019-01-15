#include<stdio.h>
#include<stdlib.h>
int main(){
  pid_t pid;
  int i;
  pid=fork();
  if(pid<0){
   printf("fork()  error\n");
   exit(1);
  }
  else if(pid==0){
     printf("this is child :pid= %d  parent pid=%d\n",getpid(),getppid());
  }
  else{
    printf("this is parent:pid=%d, parent pid=%d\n",getpid(),getppid());
  }
  i=0;
  for(;i<4;i++){
     printf("thus is %d,i=%d\n",getpid(),i);
	 sleep(3);
  }
}
