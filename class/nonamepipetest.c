#include"pipe.h"
#define MAX_LINE 80
int main(){
	int fd[2],ret;
	char buf[MAX_LINE+1];
	const char *testbuf="this is a test string";
	if(pipe(fd)==0){
		if(fork()==0){
			ret=read(fd[0],buf,MAX_LINE);
			buf[ret]=0;
			printf("Child read %s\n",buf);

		}else{
			ret=write(fd[1],testbuf,strlen(testbuf));
			ret=wait(NULL);
		}
	}
	close(fd[0]);
	close(fd[1]);
	return 0;
}
