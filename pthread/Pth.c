#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>>
#include<sys/types.h>

void * fun(void *argv){
 printf("child thread %d,ppid=%d\n",getpid(),getppid());
}
int main(){
  pthread_t tid;
  int error;
  error=pthread_create(&tid,NULL,fun,NULL);
  if(error!=0){
   printf("failed!!\n");
   return -1;
  }
  printf("parent pid=%d,tid=%d\n",getpid(),tid);
  return 0;

}
