#include"pipe.h"
int main(int argc,char **argv){
	int fd;
	char w_buf[4096*2];
	int real_wnum;
	memset(w_buf,0,4096*2);
	if((mkfifo(FIFO_SERVER,O_CREAT|O_EXCL)<0)&&(errno!=EEXIST))
		printf("cannot create fifoserver\n");
	if(fd==-1)
		if(errno==ENXIO)printf("open error; no reading process\n");
	fd=open(FIFO_SERVER,O_WRONLY | O_NONBLOCK,0);
	real_wnum=write(fd,w_buf,2048);
	if(real_wnum==-1){
		if(errno==EAGAIN)printf("write to file error:try later\n");
	}
	     else
			 printf("real write num is %d\n",real_wnum);
			 real_wnum=write(fd,w_buf,5000);
			 if(real_wnum==-1)if(errno==EAGAIN)printf("try later\n");
	}


