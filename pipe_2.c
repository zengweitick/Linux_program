#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>
#include<fcntl.h>
#include<errno.h>
void sigfun(int signo){
  if(signo==SIGPIPE)printf("Hello I get the signal:SIGPIPE and signum=%d\n",signo);

}
int main(){

	int fd[2];
	if(signal(SIGPIPE,sigfun)==SIG_ERR){

   perror("sigfun bind failed\n");
   exit(0);;
	}
	if(pipe(fd)==-1){
		perror("pipe create error\n");
		exit(1);
	}
	pid_t pid;
	pid=fork();
	if(pid==-1){

		perror("fork error\n");
		exit(-1);
	}
	else if(pid==0){
		printf("[Child] i will close the last read end of pipe\n");
		close(fd[0]);
		return 0;
	}
	else {

		close(fd[0]);
		sleep(1);
		int ret=write(fd[1],"Hello world",11);
		if(ret==-1){
			printf("[Parent] write failed! and errno=%s\n",strerror(errno));
		}
		return 0;
	}
}
