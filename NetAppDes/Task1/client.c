#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>		

#define BACKLOG 5
#define MAXDATASIZE 128
#define PORT 3000

int addr_conv(char *address,struct in_addr *inaddr);

int main(int argc,char **argv){
	int sockfd,nbytes,new_fd;
	int port=PORT;
	int surviveTime = 0;
	char buf[MAXDATASIZE];
	struct sockaddr_in srvaddr;
	if(argc!=2 && argc!=3  && argc!=4){
		printf("usage:./client hostname|ip. Or usage:./client hostname|ip port|survive time(s)\n");
		exit(0);
	}
	if(argc==3)
		port=atoi(argv[2]);
	if(argc==4)
	{
		port=atoi(argv[2]);
		surviveTime=atoi(argv[3]);
	}
	//1.创建网络端点
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1){
		printf("can;t create socket\n");
		exit(1);
	}
	//指定服务器地址（本地socket地址采用默认值）
	bzero(&srvaddr,sizeof(srvaddr));
	srvaddr.sin_family=AF_INET;
	srvaddr.sin_port=htons(port);
	
	if(inet_aton("127.0.0.1",&srvaddr.sin_addr)==-1){
		printf("addr convert error\n");
		exit(1);
	}
	
	if(addr_conv(argv[1],&srvaddr.sin_addr)==-1){
		perror(strerror(errno));
	}
	//2.连接服务器
	if(new_fd = connect(sockfd,(struct sockaddr *)&srvaddr,sizeof(struct sockaddr))==-1){
		printf("connect error\n");
		exit(1);
	}
	//3.发送请求
	sprintf(buf,"server time:%d",surviveTime);
	send(sockfd,buf,strlen(buf),0);
	//4.接收响应
	if((nbytes=recv(sockfd,buf,MAXDATASIZE,0))==-1){
		printf("read error\n");
		exit(1);
	}
	buf[nbytes]='\0';
	printf("srv respons:%s\n",buf);
	sleep(surviveTime);
	//关闭socket
	close(sockfd);
	return 0;
}

int addr_conv(char *address,struct in_addr *inaddr){
	struct hostent *he;
	if(inet_aton(address,inaddr)==1){
		printf("call inet_aton sucess.\n");
		return 0;
	}
	printf("call inet_aton fail.\n");
	he=gethostbyname(address);
	if(he!=NULL){
		printf("call gethostbyname sucess.\n");
		*inaddr=*((struct in_addr *)(he->h_addr_list[0]));
		return 0;
	}
	return -1;
}
