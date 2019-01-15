#include"sid.h"
int main(){
	 pid_t pid;
	 pid_t sid;
	 if((pid=fork())<0){
		 printf("fork error");
		 return -1;
	 }
	 else if(pid==0){
		 sid=getsid(getpid());
		 printf("1.sid[%d]\n",sid);
		 sid=setsid();
		 if(sid<0)perror("setsid");
		 printf("2.sid[%d]\n",sid);
	 }
	 
	 while(1)sleep(1);
	 return 0;

}
