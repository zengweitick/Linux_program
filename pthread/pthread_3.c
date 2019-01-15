#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
pthread_t tid;
void *func();
int main(){
   if(pthread_create(&tid,NULL,func,NULL)!=0){
      printf("Create pthread error\n");
	  exit(1);
   }
   printf("This is parent and the tid is:%lu\n",tid);
   printf("This parent and pid is:%d, tid:%lu\n",getpid(),pthread_self());
   sleep(1);
   return 0;
   }
void *func(){
   printf("this is new thread and new process pid is:%d,tid:%lu\n",getpid(),pthread_self());
   printf("new process :pid:%ld,tid:%lu\n",getpid(),tid);
   pthread_exit(NULL);

}
