#include"pthread.h"
void *fun(void *argv){
	char *name=(char*)argv;
	int i;
	for(i=1;i<10;i++){
		printf("%s :%d\n",name,i);
	    if(strcmp("Alen",name)==0){
			usleep(1000*10);
		}
		else{
			usleep(1000*5);
		}
	}

		return NULL;

}
int main(){
	int err;
	pthread_t alen,luffy;
	char *name1="Alen";
	char *name2="Luffy";
	err=pthread_create(&alen,NULL,fun,(void*)name1);
	err=pthread_create(&luffy,NULL,fun,(void*)name2);
    sleep(5);
	printf("Alen id: %lx\n",alen);
	printf("Luffy id :%ld\n",luffy);
	return 1;
}
