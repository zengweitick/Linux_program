#include<unistd.h>
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ERR(name,err) do {printf("%s : %s",#name,strerror(err));exit(-1);}while(0);
int excute;
void clean(void *arg){
	printf("clean :%s\n",(char*)arg);
}
void *th_fun1(void *arg){
	puts("thread 1 starting");
	if(arg){
		printf("线程 1 提前退出\n");
		return (void *)1;
	}
	pthread_cleanup_push(clean,"线程  1 清理者 1");
	pthread_cleanup_push(clean,"线程  1 清理者 2");
	 

	pthread_cleanup_pop(excute);
	pthread_cleanup_pop(excute);
    printf("线程 1 正常退出\n");
	return (void*)10;
}
void *th_fun2(void *arg){
	puts("thread 2 starting");
	pthread_cleanup_push(clean,"线程  2  清理者 1");
	pthread_cleanup_push(clean,"线程  2  清理者 2");
	if(arg){
		printf("线程 2提前退出\n");
		pthread_exit((void *)2);
	}
	pthread_cleanup_pop(excute);
	pthread_cleanup_pop(excute);
	printf("线程 2 正常退出\n");
	pthread_exit((void *)20);
}
int main(int argc, char **argv){
	if(argc<3){
		printf("Usage:%s <arg 0 | 1>",argv[0]);
		return -1;
	}
	pthread_t td1,td2;
	int err;
	void *ret;
	void *arg=NULL;
	excute=0;
	arg=(void*)atoi(argv[1]);
	excute=atoi(argv[2]);
	err=pthread_create(&td1,NULL,th_fun1,arg);
	if(err!=0)ERR(pthread_create1,err);
	
	err=pthread_create(&td2,NULL,th_fun2,arg);
	if(err!=0)ERR(pthread_create2,err)
    err=pthread_join(td1,&ret);
	if(err!=0)ERR(pthread_join1,err);
	printf("thread 1 exit code %d\n",(int)ret);
    err=pthread_join(td2,&ret);
	if(err!=0)ERR(pthread_join2,err);
	printf("thread 2 exit code %d\n",(int)ret);
}
