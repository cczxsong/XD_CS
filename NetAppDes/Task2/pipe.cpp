/*
pipe.cpp
author@cczxsong 
*/
#include<unistd.h>
#include<iostream>
#include<stdio.h> 
#include<stdlib.h> 
#include<errno.h> 
#include<sys/types.h>
#include<wait.h>
#include<string.h>

using namespace std;

int main(int argc,char **argv)
{
	int pipe1[2],pipe2[2];
	int pid1,pid2;
	int n;
	//char pstr[]="parent data";
	char cstr[]="this massage is from child1";
	char buf1[128];
	char buf2[128];
	
	memset(buf1,'\0',128); //初始化
	memset(buf2,'\0',128);
	if(pipe(pipe1)<0||pipe(pipe2)<0)
		cout<<"pipe error"<<endl;
	//pid_t pid1=fork();
	//pid_t pid2=fork();
	if((pid1=fork())==-1)
	{
		printf("childprocess1 failed!");
	}
	else if(pid1 > 0)
	{
		//父进程,用管道1读数据,管道2写数据
		cout<<"father PID:"<<getpid()<<endl;
		//close(pipe1[1]);//关闭pipe1写端口
		//close(pipe2[0]);//关闭pipe2读端口
		if(read(pipe1[0],buf1,100)>0)
			cout<<"father received:"<<buf1<<endl;
		write(pipe2[1],buf1,strlen(buf1));
	}	
	else if(pid1==0)
	{
		cout<<"child1 PID:"<<getpid()<<endl;
		//子进程用管道1写数据
		close(pipe1[0]);//关闭pipe1读端口
		close(pipe2[0]);//关闭pipe2读端口
		close(pipe2[1]);//关闭pipe2写端口
		write(pipe1[1],cstr,strlen(cstr));
	}
	
	if((pid2=fork())==-1)
	{
		printf("childprocess2 failed!");
	}
	else if(pid2==0)
	{
		//子进程用管道2读数据
		close(pipe1[0]);//关闭pipe1读端口
		close(pipe1[1]);//关闭pipe1写端口
		close(pipe2[1]);//关闭pipe2写端口
		if(read(pipe2[0],buf2,128)>0)
		{
			//cout<<"child2 received:"<<buf2<<endl;
			printf("In child2 : pid=%d\n",getpid());
			printf("In child2 : buf=%s\n",buf2);
			exit(0);
		}
	}
	return 0;
}