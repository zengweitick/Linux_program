#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
pthread_barrier_t b;
void *fun(void *arg){
	int id=(int)arg;
	printf("Hello, I'am thread [%d]\n",id);
	int res;
	res=pthread_barrier_wait(&b);
	printf("Thread[%d] returning [%d]\n",id,res);
	return NULL;
}
int main(){
	int i,res=0;
	pthread_t tid[10];
	printf("PTHREAD_BARRIER_SERIAL_THREAD=%d\n",PTHREAD_BARRIER_SERIAL_THREAD);
	pthread_barrier_init(&b,NULL,11);
	for(i=0;i<10;i++){
		pthread_create(&tid[i],NULL,fun,(void*)i);
	}
	res=pthread_barrier_wait(&b);
	printf("thread [main] returning [%d]\n",res);
	for(i=0;i<10;i++){

		pthread_join(tid[i],NULL);
	}
	pthread_barrier_destroy(&b);
	return 0;
}
