#include"pthread.h"
struct Ticket{
    int number;
	pthread_rwlock_t rwlock;
	pthread_mutex_t mutex;
}ticket;
int lock=0;
void *query(void *arg){
	int name=(int )arg;
	sleep(rand()%5+1);
	if(lock==1)pthread_rwlock_rdlock(&ticket.rwlock);
	else if(lock==2)pthread_mutex_lock(&ticket.mutex);
	int number=ticket.number;
	sleep(1);
	printf("%03d query :%d\n",name,number);
	if(lock==1)pthread_rwlock_unlock(&ticket.rwlock);
	else if(lock==2)pthread_mutex_unlock(&ticket.mutex);
	return NULL;
}
void *buy(void *arg){
	int name=(int)arg;
	if(lock==1)pthread_rwlock_wrlock(&ticket.rwlock);
	else if(lock==2)pthread_mutex_lock(&ticket.mutex);
	int number=ticket.number;
	number-=10;
	sleep(1);
	ticket.number=number;
	printf("%03d buy 10 tickets\n",name);
	if(lock==1)pthread_rwlock_unlock(&ticket.rwlock);
	else if(lock==2)pthread_mutex_unlock(&ticket.mutex);
	sleep(rand()%5+2);
	return NULL;
}
int main(int argc,char **argv){
	lock=0;
	if(argc>=2)lock=atoi(argv[1]);
	int names[100];
	pthread_t tid[100];
	for(int i=0;i<100;++i)names[i]=i;
	ticket.number=1000;
	printf("remain tickets= %d\n",ticket.number);
	pthread_rwlock_init(&ticket.rwlock,NULL);
	pthread_mutex_init(&ticket.mutex,NULL);
	for(int i=0;i<100;++i){
		 if(i%10==0)pthread_create(&tid[i],NULL,buy,(void *)names[i]);
		 else pthread_create(&tid[i],NULL,query,(void *)names[i]);

	}
	for(int i=0;i<100;++i){
		pthread_join(tid[i],NULL);
	}
	pthread_rwlock_destroy(&ticket.rwlock);
	pthread_mutex_destroy(&ticket.mutex);
	return 0;
}

