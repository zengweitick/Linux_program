#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
 pid_t pid;
 printf("Before fork()\n");

 int i=5;
 while(i--){
   p=fork();
   if(p==0)break;
   else if(p<0){
   printf("fork error!\n");
   return 1;
   }
 }
  if(p==0){

    printf("I am child:%d,my father is :%d\n",getpid(),getppid());
	return 0;
  }
   while(1){
    sleep(3);
	printf("Hello ,I am father\n");
   }
return 0;
}
