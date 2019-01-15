#include"pthread.h"
int ticket=3;
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
void *alen(void *arg){
      int n=0;
	 while(1){
		 usleep(1000*10);
		 if(ticket>0){
			 pthread_mutex_lock(&lock);
			 ticket--;
			 n++;
			 usleep(1000*10);
			 
		 }
		 else{
			 break;
		 } 
		 pthread_mutex_unlock(&lock);
	 }
	 printf("alen :I get %d tickets\n",n);

	 return NULL;
}
void *luffy(void *arg){
   int n=0;
   while(1){
	   usleep(1000*10);
	   if(ticket>0){
		  pthread_mutex_lock(&lock);
		  ticket--;
		   n++;
		   usleep(1000*10);
	   }
	   else {
		   break;
	   }
       pthread_mutex_unlock(&lock);
   }
   printf("luffy: I get %d tickets\n",n);
   return NULL;
}
int main(){
	pthread_t td1,td2;

    pthread_create(&td1,NULL,alen,NULL);
	pthread_create(&td2,NULL,luffy,NULL);
	pthread_join(td1,NULL);
	pthread_join(td2,NULL);
	return 0;
}
