#include"fifo.h"
int main(){
	printf("this is [%d]\n",getpid());
	char buf[64];
	int n=0;
	int fd=open("hello",O_RDONLY);
	if(fd<0){
		perror("open fifo\n");
		return -1;
	}
	puts("Has opened fifo");
	while((n=read(fd,buf,64))>0){

		write(STDOUT_FILENO,buf,n);

	}
	if(n==0){
		puts("remote closed");
	}
	else{
		perror("read fifo");
		return -1;
	}
	close(fd);
	return 0;
}
