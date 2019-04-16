#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>		
#include <sys/socket.h>		//pthread_t , pthread_attr_t and so on.
#include <netinet/in.h>		//structure sockaddr_in
#include <sys/select.h>
#include <errno.h>
#include <pthread.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>		//Func :close,write,read
#include <sys/ipc.h>
#include <sys/msg.h>	//messageQueue


#define BACKLOG 5
#define MAXDATASIZE 128
#define PORT 3000
#define MAX_CONN_LIMIT 10 		//MAX connection limit
#define BUFFER_LENGTH 1024
//static void message(void * new_fd);
int main(int argc,char **argv){
	int sockfd,new_fd,nbytes,sin_size;
	int port=PORT;
	char buf[MAXDATASIZE]={'\0'};
	struct sockaddr_in srvaddr,clientaddr;
	int running = 0;
	int msgid;
	key_t unique_key;
	const int id = 1000;
	
	struct msgbuf {
		int msgtype;
		int msgtext; //0��ʾ+1,1��ʾ-1,��������
    }sndmsg, rcvmsg;
    //��Ϣ���еĴ���
	if((msgid = msgget(unique_key, IPC_CREAT |  0666)) == -1) {
		fprintf(stderr, "msgget error!\n");
		exit(1);
    }
    
	//��������˵�
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1){
		printf("can;t create socket\n");
		exit(1);
	}
	
	if(argc==2 && argc!=3){
		int on=1;
		setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));
		printf("reuse addr\n");
	}
	if(argc==3)
		port=atoi(argv[2]);
	//����ַ
	bzero(&srvaddr,sizeof(srvaddr));
	srvaddr.sin_family=AF_INET;
	srvaddr.sin_port=htons(port);
	srvaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	//��ַ������
	if(inet_aton(argv[1],&srvaddr.sin_addr)==-1){
		printf("addr convert error\n");
		exit(1);
	}
	
	//�󶨷�������ַ�Ͷ˿�
	if(bind(sockfd,(struct sockaddr *)&srvaddr,sizeof(struct sockaddr))==-1){
		printf("bind error\n");
		exit(1);
	}
	//�����˿�
	if(listen(sockfd,BACKLOG)==-1){
		printf("listen error\n");
		exit(1);
	}
	printf("server is live,waiting for client\n");
	for(;;){
		//���ܿͻ�������
		pthread_t thread_id;
		
		sin_size=sizeof(struct sockaddr_in);
		if((new_fd=accept(sockfd,(struct sockaddr *)&clientaddr,&sin_size))==-1){
			printf("accept error\n");
			continue;
		}
		/*//���߳�
		if(pthread_create(&thread_id,NULL,(void *)(&message),(void *)(&new_fd)) == -1)
		{
			fprintf(stderr,"pthread_create error!\n");
			break;
		}
		*/
		
		//printf("current process num:%d\n",running);
		char strx[] = "server time:"; //�ַ���ǰ׺
		char dest[MAXDATASIZE] = {""};
		//char str[MAXDATASIZE];
		int pid = fork();
		//�ӽ���
		if(pid == 0){ 	
			
			sndmsg.msgtype = id;
			sndmsg.msgtext = 0;
			if(msgsnd(msgid, (struct msgbuf *)&sndmsg, MAXDATASIZE, 0) == -1) {
				fprintf(stderr, "msgsnd error! \n");
				exit(2);
			}
			
			close(sockfd);
			printf("\nclient addr:%s PID:%d PPID:%d\n",inet_ntoa(clientaddr.sin_addr),getpid(),getppid());
			//��������
			//printf("5");
			nbytes=read(new_fd,buf,MAXDATASIZE);
			buf[nbytes]='\0';
			printf("clientmesg:%s\n",buf);
			//������Ӧ
			send(new_fd,buf,strlen(buf),0);
			
			//��ȡ�ӽ��̵�����ʱ��
			int pos = strstr(buf, strx)-buf+strlen(strx);
			strncpy(dest, buf+pos, MAXDATASIZE);
			int tim = atoi(dest);
			
			sndmsg.msgtext = tim;
			int stau;
			if(stau = msgsnd(msgid, (struct msgbuf *)&sndmsg, MAXDATASIZE, 0) == -1) {
				fprintf(stderr, "msgsnd error! \n");
				exit(2);
			}
			
			sleep(tim);	
			printf("\nclient addr:%s PID:%d closed\n",inet_ntoa(clientaddr.sin_addr),getpid());
			//�ر�socket
			close(new_fd);
			exit(0);
		}
		
		else if (pid > 0){
			sleep(3);
			//running++;
			//printf("current process num:%d\n",running);
			if((msgrcv(msgid, (struct msgbuf *)&rcvmsg, MAXDATASIZE, id, IPC_NOWAIT)) == 0) {
				fprintf(stderr, "msgrcv error!\n");
				//break;
				exit(4);
			}
			sleep(rcvmsg.msgtext);
			//printf("rcvmsg.msgtext:%d\n",rcvmsg.msgtext);
			if(rcvmsg.msgtext == 0)running++;
			if(rcvmsg.msgtext != 0)running--;
			//running--;
			printf("current process num:%d\n",running);
		}
	}
	msgctl(msgid, IPC_RMID, 0);   // delete the message queue 
	return 0;
}
/*
//���̰߳��ͨ�ź���
static void message(void * sock_fd){
	int new_fd = *((int *)sock_fd);
	int nbytes;
	char buf[MAXDATASIZE];
	//��������
	nbytes=read(new_fd,buf,MAXDATASIZE);
	buf[nbytes]='\0';
	printf("client:%s\n",buf);
	//������Ӧ
	write(new_fd,buf,strlen(buf));
	//�ر�socket
	close(new_fd);
	pthread_exit(NULL);
}
*/
