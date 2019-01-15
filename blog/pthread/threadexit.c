#include"pthread.h"
#define ERR(name,err) do{printf("%s :%s \n",#name,strerror(err));exit(-1);}while(0);
void *th_fun1(void* arg){
	puts("thread_1_returning");
	return (void*)10;
}
void *th_fun2(void* arg){
	puts("thread_2_exiting");
	pthread_exit((void*)20);
	puts("thread 2 exited");
}
int main(){
	pthread_t td1,td2;
	int err;
	void *ret;
	err=pthread_create(&td1,NULL,th_fun1,NULL);
	if(err!=0)ERR(pthread_create1,err);
	err=pthread_create(&td2,NULL,th_fun2,NULL);
	if(err!=0)ERR(pthread_create2,err);
	sleep(2);
	err=pthread_join(td1,&ret);
	if(err!=0)ERR(pthread_join1,err);
	printf("thread 1 exit code %d\n",(int)ret);
	err=pthread_join(td2,&ret);
	if(err!=0)ERR(pthread_join2,err);
	printf("thread 2 exit code %d\n",(int)ret);
	return 0;
    
}
