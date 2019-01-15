#include"file.h"
int main(){
  printf("Before fork()\n");
  int n=5;
  pid_t pid;
  int status;
  while(n--){
    pid=fork();
	if(pid==0)break;
	else if(pid<0)return -1;
   
  }
  if(pid==0){
    sleep(2*n+1);
     printf("I am child %d,my father is %d\n",getpid(),getppid());
     if(2*n+1==3) *((int *)0)=0;
		 return 4*n+1;
  }
   while(1){
   pid=waitpid(-1,&status, WUNTRACED | WCONTINUED);
	   if(pid==-1){
        perror("wait");
		sleep(5);
        printf("I am father[%d],I have wiped out all zombie\n\n",getpid());
		return 1;
	   }
	   else if(pid==0){
       printf("Hello ,I am father I am waiting my child\n\n");
	   }
	   else {
          if(WIFEXITED(status)){
            printf("Child [%d]<exited> with code [%d]\n\n",pid,WEXITSTATUS(status));
		  }
		  else if(WIFSIGNALED(status)){
           printf("child [%d]<terminated> abornormal,signal[%d]\n\n",pid,WTERMSIG(status));
#ifdef WCOREDUMP
		   if(WCOREDUMP(status)){
              printf("<core file generated> in chilf[%d]\n\n",pid);
		   }
#endif
 
		  }
		  else if(WIFSTOPPED(status)){
          printf("child[%d] <stopped ,signal[%d]\n\n>",pid,WSTOPSIG(status));
		  }
		  else if(WIFCONTINUED(status)){
          printf("child[%d]<continued>\n\n",pid);
		  }
		  
	   }

   }
   return 0;
 }

