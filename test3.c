#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *fp;
	char *buf=NULL;
	size_t len=0;
	ssize_t n;
	fp=fopen("1_1","r");
	if(fp==NULL){
		exit(EXIT_FAILURE);
	}
	while(n=getline(&buf,&n,fp)!=-1){
		printf("Receive line of lenth %zu:\n",n);
		printf("%s",buf);
	}
	if(buf)free(buf);
	exit(EXIT_SUCCESS);
}
