#include"process.h"
int main(){
	pid_t sid,pid;
	pid=fork();
	if(pid==0){
		sid=getsid(getpid());
		printf("sid =%d\n",sid);
		sid=setsid();
		if(sid<0){
           perror("setsid");
		}
		printf("sid=%d\n",sid);
	}
	while(1)sleep(1);
	return 0;
}
