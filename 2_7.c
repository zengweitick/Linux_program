#include"ch02.h"
#include"y_or_n_ques.c"
int main(){
 int answer;
 fprintf(stdout,"1:this is a buffer test program. ");
 fprintf(stderr,"2:---test message\n");
 answer=y_or_n_ques("3:Hello,Are you a student ?");
 if(answer==1)
	 printf("4:Hope you have high score. ");
 else
	 printf("4:Hope you good salary.");
 fflush(stdout);
 fprintf(stderr,"5:bye!\n");
 return 0;
}
