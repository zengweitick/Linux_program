#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
int main(){
 struct stat buf;
 char *ptr;
 stat("/etc/passwd",&buf);
 if(S_ISREG(buf.st_mode))ptr="regular";
 else if(S_ISDIR(buf.st_mode))ptr="directory";
 else if(S_ISCHR(buf.st_mode))ptr="character special";
 else if(S_ISBLK(buf.st_mode))ptr="block special";
 else if(S_ISFIFO(buf.st_mode))ptr="fifo";
 printf("/etc/passwd :%s\n",ptr);
 return 0;

}
