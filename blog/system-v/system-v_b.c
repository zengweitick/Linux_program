#include"system-v.h"
int main(){
	int id=shmget(0x8888,0,0);
    if(id<0){
		perror("shmget");
		return -1;
	}
	printf("id=%d\n",id);
	char *buf=shmat(id,NULL,0);
	if(buf==(char *)-1){
		perror("shmat");
		return -1;
	}
	printf("%s",buf);
	if(shmdt(buf)<0){
		perror("shmdt");
		return -1;
	}
	if(shmctl(id,IPC_RMID,NULL)<0){
		perror("shmctl");
		return -1;
	}
	return 0;
}
