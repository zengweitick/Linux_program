#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
int show_type(char *pathname);
int main(int argc,char **argv){
	int i;
	for(i=1;i<argc;i++){
		printf("%s:",argv[i]);
		show_type(argv[i]);
		printf("\n");
	}
	exit(0);
}
int show_type(char *pathname){
	struct stat buf;
	if(lstat(pathname,&buf)==-1){
		printf("lstat error");
		return -1;
	}
	if(S_ISREG(buf.st_mode))printf("regular");
	else if(S_ISDIR(buf.st_mode))printf("directory");
    else if(S_ISCHR(buf.st_mode))printf("char");
	else if(S_ISBLK(buf.st_mode))printf("block special");
	else if(S_ISFIFO(buf.st_mode))printf("fifo file");
	else if(S_ISLNK(buf.st_mode))printf("symblic link");
	else if(S_ISSOCK(buf.st_mode))printf("socket");
	else printf("unknown mode");
	return 0;
}
