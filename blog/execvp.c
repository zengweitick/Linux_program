#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int  main(){
//	char *input[]={"./","time",NULL};
  // if(execvp("time",input)==-1){
  // perror("exec");
  // return 1;
  // }
	system("./time");
   return 0;

}
