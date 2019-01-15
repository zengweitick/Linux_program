#include"ch02.h"
#define BUFSIZE 200
int main(int argc,char *argv[]){
  FILE *from ,*to;
  int n;
  char buffer[BUFSIZE];
  if(argc!=3){
	  fprintf(stderr,"Usage:%s from file to file\n",*argv);
	  exit(1);
      }
  if((from=fopen(argv[1],"r"))==NULL)
	 err_exit(argv[1]);
 if((to=fopen(argv[2],"a"))==NULL)
	 err_exit(argv[2]);
 while((n=fread(buffer,sizeof(char),BUFSIZE,from))>0)
    fwrite(buffer,sizeof(char),n,to);
 fclose(from);
 fclose(to);
 exit(0);
}
