#include<stdio.h>
#include<pthread.h>
int flag=0;
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;

void *signal(void *arg){
	  while(1){
		 pthread_mutex_lock(&lock);
		 flag=1;
		 pthread_mutex_unlock(&lock);
		 pthread_cond_signal(&cond);
	     sleep(2);	
		 printf("发送完成....\n");
	  }
}
void *print(void *arg){	
	
	pthread_mutex_lock(&lock);
	while(flag==0){
		pthread_cond_wait(&cond,&lock);
	}
	printf("%s\t",arg);
	pthread_mutex_unlock(&lock);
}
int main(){
	pthread_t td1,td2,td3,td4,td5;
	while(1){
	pthread_create(&td1,NULL,print,"A");
	pthread_create(&td2,NULL,print,"B");
	pthread_create(&td3,NULL,print,"C");
	pthread_create(&td4,NULL,print,"D");
	pthread_create(&td5,NULL,signal,NULL);
    pthread_join(td1,NULL);
    pthread_join(td2,NULL);
    pthread_join(td3,NULL);
    pthread_join(td4,NULL);
	pthread_join(td5,NULL);
	flag=0;
	}
    return 0;
}
