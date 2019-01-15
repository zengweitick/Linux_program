#include"pipe.h"
main(int argc,char **argv){
	char r_buf[4096*2];
	int fd;
	int r_size;
	int ret_size;
	r_size=atoi(argv[1]);
	printf("requred real read bytes %d\n",r_size);
	memset(r_buf,0,sizeof(r_buf));
	fd=open(FIFO_SERVER,O_RDONLY | O_NONBLOCK,0);
	if(fd ==-1){
		printf("open %s for read error\n");
		exit(-1);
	}
while(1){
	memset(r_buf,0,sizeof(r_buf));
	ret_size=read(fd,r_buf,r_size);
	if(ret_size==-1)
		if(errno==EAGAIN)
			printf("NO DATA\n");
		printf("real read bytes %d\n",ret_size);
		sleep(1);
		pause();
		unlink(FIFO_SERVER);
}
}
