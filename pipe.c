#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
int main(){

	pid_t pid;
	int r_num, w_num;
	int pipe_fd[2];
	char buf_r[4896];
	char buf_w[4896];
	memset(buf_r,0,sizeof(buf_r));
	if(pipe(pipe_fd)<0){

		printf("创建管道失败\n");
		return -1;
	}
	pid=fork();
	if(pid<0){
		perror("创建子进程失败\n");
		return -1;
	}
	else if(pid==0){
     //		close(pipe_fd[1]);
		while(1){

			r_num=read(pipe_fd[0],buf_r,1000);
			printf("[Child]readnum is %d\n",r_num);
			if(r_num==0){
				printf("子进程从管道读取%d个字符，读取的字符串是:EOF\n",r_num);
				break;
			}

		}
		close(pipe_fd[0]);
		exit(0);
	}
	else{

		close(pipe_fd[0]);
		memset(buf_w,0,sizeof(buf_w));
		if((w_num=write(pipe_fd[1],buf_w,1024))==-1)printf("[Parent] write pipeerror\n");
		else
			printf("[Parent] write %d byties \n",w_num);
			sleep(15);
			printf("[Parent] will close pipe!\n");
			close(pipe_fd[1]);
			sleep(2);
			close(0);
	}
}
