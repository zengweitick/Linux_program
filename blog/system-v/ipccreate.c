#include "system-v.h"

int main(int argc, char *argv[])
{
 if(argc<3){
	 printf("%s <ipc type> <key>\n",argv[0]);
	 return -1;
 }
 key_t key=strtoll(argv[2],NULL,16);
 char type=argv[1][0];
 char buf[64];
 int id;
 if(type=='0'){
	 id=shmget(key,getpagesize(),IPC_CREAT | IPC_EXCL | 0644);
	 strcpy(buf,"share memory");
 }
 else if(type=='1'){
	 id=msgget(key,IPC_CREAT | IPC_EXCL | 0644);
	 strcpy(buf,"message queue");
 }
 else if(type=='2'){
     id=semget(key,5,IPC_CREAT | IPC_EXCL |0644);
     strcpy(buf,"semaphore");	 
	 }
 else {

	 printf("type must be 0,1,2\n");
	 return -1;
 }
 if(id<0){
	perror("get error");
	return -1;
 }
 printf("create %s at 0x%x ,id=%d\n",buf,key,id);
 return 0;

 
	
}
