#include"pthread.h"
pthread_mutex_t mutex;
void *fun1(void* fp);
void *fun2(void *fp);
int main(){
	FILE * fp;
	pthread_t td1,td2;
	fp=fopen("test.txt","a+");
        pthread_create(&td1,NULL,fun1,fp);
	pthread_create(&td2,NULL,fun2,fp);
	pthread_join(td1,NULL);
	pthread_join(td2,NULL);
    fclose(fp);
	return 0;

}
void *fun1(void* fp){
  int i=1;
  for(;i<=50;i++){
     
	 pthread_mutex_lock(&mutex);
	 fprintf(fp,"%d\t",2*i-1);
	pthread_mutex_unlock(&mutex);
   usleep(200);	
  }
}
void *fun2(void *fp){
  int i=1;
  for(;i<=50;i++){
          
	  pthread_mutex_lock(&mutex);
	  fprintf(fp,"%d\t",2*i);
	  pthread_mutex_unlock(&mutex);
	  usleep(200);
  }
}
