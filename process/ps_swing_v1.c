#include"process.h"
int main(){
	pid_t pid;
	int i=1;
	int group1,group2;
    setpgid(getpid(),getpid());
	group1=getpid();
	for(i=1;i<=3;i++){
		pid=fork();
		if(pid==0){
           if(i==1){
			   setpgid(getpid(),group1);
		   }
		   else if(i==2){
               FILE* fp=fopen("buffer","w");
			   setpgid(getpid(),getpid());
			   group2=getpid();
			   printf("enter file,group2=%d\n",group2);
			   fprintf(fp,"%d",group2);
			   fclose(fp);
		   }
		   else if(i==3){
			   int  add;
			   FILE* fp=fopen("buffer","r");
			   fscanf(fp,"%d",&add);
			   printf("get group2,and group2=%d\n",add);
			   setpgid(getpid(),add);
		       fclose(fp);
		   }
		   break;
		}
	}
	printf("进程 %d,pid:[%d],ppid[%d],pgid[%d]\n",i%4,getpid(),getppid(),getpgid(getpid()));
	while(1)sleep(1);
	return 0;
}
