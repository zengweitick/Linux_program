#include"pthread.h"
#define ERR(name,err)do{printf("%s:%s\n",#name,strerror(err));exit(-1);}while(0);
void* fun1(void *arg){
	while(1){
		puts("thread 1 runing");
		sleep(1);
	}
	return (void *)10;
}
void* fun2(void *arg){
	while(1){
       puts("thread 2 runing");
	   sleep(1);
	}
	pthread_exit((void *)20);
}
int main(){
	pthread_t td1,td2;
	int err;
	void *ret;
	err=pthread_create(&td1,NULL,fun1,NULL);
	if(err!=0)ERR(pthread_create1,err);
	err=pthread_create(&td2,NULL,fun2,NULL);
	if(err!=0)ERR(pthread_create2,err);
	sleep(5);
	pthread_cancel(td1);
	pthread_cancel(td2);
	err=pthread_join(td1,&ret);
	printf("PTHREAD-CANCEL  =%d\n",(int)PTHREAD_CANCELED);
	if(err!=0)ERR(pthread_join1,err);
	printf("thread 1 exit code %d\n",(int)ret);
	err=pthread_join(td2,&ret);
	if(err!=0)ERR(pthread_join2,err);
	printf("thread 2 exit code %d\n",(int) ret);
	return 0;
}
