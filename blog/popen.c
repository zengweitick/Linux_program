#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<sys/wait.h>
#include<signal.h>
#define maxlinesize 8192
void print_wait_exit(int status){
 printf("status=%d\n",status);
 if(WIFEXITED(status)){
     printf("normal termination ,exit status=%d\n",WEXITSTATUS(status));
   }
   else if(WIFSIGNALED(status)){
     printf("abnarmal termination.signal number =%d:%s\n",WTERMSIG(status),
     #ifdef WCOREDUMP
     WCOREDUMP(status)?"core file genated":"");
     #else 
        "");
       #endif
     
   }
} 



int main(int argc,char **argv){
  FILE *fp=NULL;
  char command[maxlinesize],buffer[maxlinesize];
  if(argc!=2){
   fprintf(stderr,"Usage:%s filename\n",argv[0]);
   exit(1);
  }
  snprintf(command,sizeof(command),"cat %s",argv[1]);
  fp=popen(command,"r");
  if(fp==NULL){
     fprintf(stderr,"Usage:%s popenfailed(%s)\n",strerror(errno));
     exit(2);
  }
  while (fgets(buffer,maxlinesize,fp)!=NULL)
  {
  fprintf(stdout,"%s",buffer);	
  }
  int ret;
  ret=pclose(fp);
  if(ret==127){
   fprintf(stderr,"bad command(%s)\n",command);
   exit(3);
  }
  else if(ret==-1){
      fprintf(stderr,"failed to get child status(%s)\n",strerror(errno));
   exit(4);  
  }
  else{
     print_wait_exit(ret);
  }
  
  exit(0); 
}
