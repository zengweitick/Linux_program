#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<signal.h>
#include<errno.h>
#include<string.h>
void sigfun(int sig){
   printf("parent catch SIGPIPE,signal=%d\n",sig);
}
int main(){
	int fd[2];
	if(signal(SIGPIPE,sigfun)==SIG_ERR){
		perror("signa bind error!\n");
		return -1;
	}
	if(pipe(fd)==-1){
		perror("pipe error\n");
		return -1;
	}
	pid_t pid;
	if(pid==0){
		printf("this is child[%d],and will close pipe\n",getpid());
		close(fd[0]);
		return -1;
	}
	else{

		close(fd[0]);
		sleep(1);
		int ret=write(fd[1],"hello",5);
		if(ret==-1)perror("parent write error%s\n",strerror(errno));
		return 0;
	}
}

