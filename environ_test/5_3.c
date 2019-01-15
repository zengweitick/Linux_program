#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include"xmalloc.c"
#include<string.h>
int main(int argc,char **argv){
   char *value;
   if(argc==1 || argc>3){
    fprintf(stderr,"Usage<environ var>[<value>]\n");
	exit(1);
   }
   value=getenv(argv[1]);
   if(value)
      printf("Valueable %s=%s",argv[1],value);
}
else
  fprintf(stderr,"varialbe is undefine\n");
if(argc==3){
  char *string=xmalloc(strlen(argv[1])+strlen(argv[2])+2);
  strcp(string,argv[1]);
  strcat(string,"=");
  strcat(string,argv[2]);
  printf("Calling putenv with: %s\n",string);
  if(putenv(string)!=0){
     free(string);
	 err_exit("putenv_error");
  }
  value=getenv(argv[1]);
  printf("New value of %s is %s\n",argv[1],value);

}
