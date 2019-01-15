#include "pipe.h"
int main(int argc, char *argv[])
{
    printf("this is parent[%d]\n",getpid());
	int fd[2];
	int n;
	char buf[64]={0};
	if(pipe(fd)<0){
		perror("pipe");
		return -1;
	}
	pid_t pid=fork();
	if(pid==0){
        printf("this is child[%d]\n",getpid());
        close(fd[1]);
        char buf[64];
        int n=0,i;
        while(1){
	  n=read(fd[0],buf,64);
	  for(i=0;i<n;i++)putchar(toupper(buf[i]));
	  if(*buf=='q'){
		  close(fd[0]);
		  exit(0);
	  }
	  if(n==0){
		  puts("no data to read!");
		  sleep(1);
	  }
  }
  exit(0);
	}
	close(fd[0]);
	while(1){
		n=read(STDIN_FILENO,buf,64);
		write(fd[1],buf,n);
		if(*buf=='q'){
			close(fd[1]);
			exit(0);
		}
	}
	return 0;
}
