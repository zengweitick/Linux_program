#include"system-v.h"
int main(){
	int id=shmget(0x8888,4096,IPC_CREAT | IPC_EXCL | 0664);
	if(id<0){
		perror("shmet");
		return -1;
	}
	printf("id=%d\n",id);
	char *buf=shmat(id,NULL,0);
	if(buf==(char *)-1){
		return -1;
	}

	strcpy(buf,"hello,share memory!\n");
     printf("buf:%s\n",buf);
	if(shmdt(buf)<0){
		perror("shmet");
		return -1;
	}
	return 0;
}
