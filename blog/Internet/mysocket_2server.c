#include"socket.h"
int main(){
	struct sockaddr_in servaddr,cliaddr;
	int sockfd,clientfd,ret;
	socklen_t cliaddrlen;
	puts("1.create sockaddr");
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr("192.168.43.138");
	servaddr.sin_port=htons(8080);
	puts("2.create socket");
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	puts("3.bind sockaddr");
	ret=bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	if(ret<0)perror("wrong");
    puts("4.listen");
	ret=listen(sockfd,5);
	if(ret<0)perror("wrong");
	while(1)pause();
	return 0;
}
