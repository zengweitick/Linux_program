#include"process.h"
int main(){
	pid_t pid;
	printf("pid[%d],ppid[%d] pgid[%d]\n",getpid(),getppid(),getpgid(getpid()));
	setpgid(getpid(),9713);
	printf("over!\n");
	while(1)sleep(3);
	return 0;
}
