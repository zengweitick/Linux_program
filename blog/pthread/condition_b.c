#include<stdio.h>
#include<pthread.h>
int finish=0;
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
void *do_homework(void *arg){
	sleep(3);
	pthread_mutex_lock(&lock);
	finish=1;
	pthread_mutex_unlock(&lock);
}
void *check(void *arg){
	sleep(2);
	pthread_mutex_lock(&lock);
	printf("老师：作业做完了吗？\n");
	while(finish==0){
		printf("学生：没啊！\n");
		pthread_mutex_unlock(&lock);
		printf("老师：好的，继续\n");
		printf("------------------------\n");
		pthread_mutex_lock(&lock);
		printf("老师：作业做完了吗？\n");
	}
	printf("学生：做完了\n");
	pthread_mutex_unlock(&lock);
	printf("老师开始检查....\n");
}
int main(){
	pthread_t td1,td2;
	pthread_create(&td1,NULL,do_homework,NULL);
	pthread_create(&td2,NULL,check,NULL);
	pthread_join(td1,NULL);
	pthread_join(td2,NULL);
  return 0;
}
