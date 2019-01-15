#include"process.h"
int main(){
	int pid,i=4;
	while(i--){
		pid=fork();
		if(pid==0){
			
			break;
		}
		else if(pid<0){
			perror("fork()");
			return -1;
		}
	}
	printf("pid:%d->ppid:%d\n",getpid(),getppid());
	while(1)sleep(1);
	return 0;
}
