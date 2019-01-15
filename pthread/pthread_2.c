#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void * thread1(){
  pthread_detach(pthread_self());
  printf("pid is :%d,tid is :%d\n",getpid(),pthread_self());
  return (void *)1;
}
int main(){
   pthread_t tid;
   void *ret;
   int err=pthread_create(&tid,NULL,thread1,NULL);
   if(err!=0){
   perror("pthread_create\n");
   return err;
   }
int temp=pthread_join(tid,&ret);
if(temp==0){
 printf("Wait  successfully");
          }
else{
   printf("wait failed\n");

}
    printf("pid is:%d,tid is:%d\n",getpid(),pthread_self());
   sleep(1);
   return 0;
}
