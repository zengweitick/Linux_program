#include<stdio.h>
#include<stdlib.h>
int main(){
   pid_t pid;
    pid=fork();
	if(pid<0){
		perror("fork error!\n");
		return -1;
	}
	if(pid==0){
		int i=1;
		for(;i<=10;i++){
           printf("this is alen[%lx] i=%d\n",getpid(),i);
		   usleep(1000*10);
		}
		exit(1);
	}
	else{
		int i;
		for(i=1;i<=10;i++){
          printf("this luffy[%lx],i=%d\n",getpid(),i);
		  usleep(1000*5);
		}
		
	}
	return 0;
}
