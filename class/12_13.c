#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<signal.h>
#include<string.h>
#include<sys/wait.h>
#include<errno.h>
#include<stdlib.h>
#define BUF_4K 4*1024
#define BUF_8K 8*1024
#define BUF_12K 12*1024
int main(){
	char a[BUF_4K];
    char b[BUF_8K];
	char c[BUF_12K];
	memset(&a,'A',sizeof(a));
	memset(&b,'B',sizeof(b));
	memset(&c,'C',sizeof(c));
	int fd[2];
	int ret=pipe(fd);
	if(ret==-1){
		fprintf(stderr,"Failed to create pipe %s\n",strerror(errno));
		exit(1);
	}
	pid_t pid;
	pid=fork();
	if(pid==0){
		close(fd[0]);
		int n=0;
		while(n++<10){
			ret=write(fd[1],a,sizeof(a));
			printf("apid=%d write %d bytes to pipe\n",getpid(),ret);
		}
		exit(0);
	}
	
      pid=fork();
	if(pid==0){
		close(fd[0]);
		int n=0;
		while(n++<10){
			ret=write(fd[1],b,sizeof(b));
			printf("apid=%d write %d bytes to pipe\n",getpid(),ret);
		}
		exit(0);
	}
	
	pid=fork();
	if(pid==0){
		close(fd[0]);
		int n=0;
		while(n++<10){
			ret=write(fd[1],c,sizeof(c));
			printf("apid=%d write %d bytes to pipe\n",getpid(),ret);
		}
		exit(0);
	}
	close(fd[1]);
	sleep(1);
	int stream=open("text.txt",O_WRONLY | O_CREAT| O_TRUNC,0644);
	char buf[1024*4]={0};
	int m=1;
	while(1){
		ret=read(fd[0],buf,sizeof(buf));
		if(ret==0)break;
		printf("n=%d pid=%d read %dbytes from pipe buf[4095]=%c\n",m++,getpid(),ret,buf[4095]);
		write(stream,buf,ret);
	}
	exit(0);
}
