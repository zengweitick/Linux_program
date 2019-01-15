#include"file.h"
int main(int argc,char **argv){
int flags;
int fd;
if(argc!=2){
  fprintf(stdout,"error!\n");
  exit(1);
  }
 fd=atoi(argv[1]);
 flags=fcntl(fd,F_GETFL);
 if(flags==-1){
   fprintf(stdout,"read error\n");
    exit(1);
 }
 if(flags&O_RDONLY)printf("O_RDONLY\n");
 if(flags&O_WRONLY)printf("O_WRONLY\n");
 if(flags&O_RDWR)printf("O_RDWR\n");
 return 0;
}
