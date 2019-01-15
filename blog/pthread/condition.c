#include<stdio.h>
#include<pthread.h>
int finished=0;
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
 void *homework(void *arg){
	 sleep(4);
	 pthread_mutex_lock(&lock);
	 finished=1;
	 pthread_mutex_unlock(&lock);
	 pthread_cond_broadcast(&cond);
	 printf("发射信号完成.....\n");
 }
void *check(void *arg){
	sleep(1);
	pthread_mutex_lock(&lock);
	printf("%s：作业写完了吗?\n",arg);
	if(finished==0){
		printf("学生：还没呐！\n");
		printf("----------------------\n");
		pthread_cond_wait(&cond,&lock);
		printf("%s：作业写完了吗?\n",arg);
	}
	printf("学生：写完了!\n");
	pthread_mutex_unlock(&lock);
	printf("老师检查作业\n");

}
int main(){
	pthread_t td1,td2;
	pthread_create(&td1,NULL,homework,"王老师");
	pthread_create(&td2,NULL,check,"陈老师");
	pthread_join(td1,NULL);
	pthread_join(td2,NULL);
	return 0;
}
