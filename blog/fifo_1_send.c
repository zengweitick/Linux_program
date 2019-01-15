#include"fifo.h"
int main(){
	printf("this is[%d]\n",getpid());
	char buf[64];
	int n=0;
	int fd=open("hello",O_WRONLY);
	if(fd<0){
		perror("open fifo error\n");
		return -1;
	}
	puts("Has opened fifo");
	while((n=read(STDIN_FILENO,buf,64))>0){
		write(fd,buf,n);
		if(*buf=='q')break;
	}
	close(fd);
	return 0;
}
