#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
   pid_t t1,t2;
   pid_t test;
   int status1,status2;
   FILE * stream;
   FILE * stream2;
   FILE * stream3;
   if((t1=fork())<0){
    printf("fork t1 error!!\n");
   }
   else if(t1==0){
      stream=fopen("8000116434.txt","w+");
      fputc(getpid(),stream);
	  fclose(stream);
	  exit(104);
   }
   else{
	   sleep(3);
      waitpid(t1,&status1,0);
	  if((t2=fork())<0){
    printf("fork t2 error!!\n");
	exit(1);
	  }
	  else if(t2==0){
        stream2=fopen("8000116434.txt","a+");
		fputc(getpid(),stream2);
		fputc(getppid(),stream2);
		fclose(stream2);
		exit(103);
	  }
	  else{
		  sleep(3);
		  char ch;
       waitpid(t2,&status2,0);
       fprintf(stdout,"process_1:%d; process_2:%d\n",status1,status2);
	    stream3=fopen("8000116434.txt","r");
		fscanf(stream3,"%c",&ch);
		while(!feof(stream3)){
          putchar(ch);
          fscanf(stream3,"%c",&ch);
		}
		fclose(stream3);
	  }
   }
 }

