/*
shm.cpp
author@cczxsong 16030120046 王松
*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <errno.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <wait.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <signal.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define	MEM_SIZE 1024

using namespace std;
int shmid;
int status;
main(int argc, char** argv)
{
	char* p_addr, *c1_addr, *c2_addr;
	key_t key;
	char* name = (char* )"/dev/shm/myshm";
	char* text = (char* )"Hello,everyone.I am CXK!";
	int pid1,pid2;
	//int semaphore=0;
	
	key=ftok(name,'a');
	if(key==-1)
	{
		perror("ftok error");
		exit(1);	
	}
	shmid=shmget(key,MEM_SIZE,0777|IPC_CREAT);
	if(shmid==-1)
	{
		perror("shmget error");
		exit(1);
	}
	if((pid1=fork())==-1)
	{
		printf("childprocess1 failed!");
	}
	else if(pid1>0)
	{
		cout<<"father PID:"<<getpid()<<endl;
		wait(&status);
		//while(semaphore != 2)sleep(0.5);
		p_addr = (char* )shmat(shmid,0,0);
		cout<<"father received:"<<p_addr<<endl;
		//semaphore = 3;
	}
	else
	{
		//semaphore = 1;
		cout<<"child1 PID:"<<getpid()<<endl;
		c1_addr = (char* )shmat(shmid,0,0);
		memset(c1_addr, '\0',1024);
		strncpy(c1_addr,text,1024);
		//semaphore = 2;
		exit(0);
	}
	//if(semaphore == 3)
	//{
		if((pid2=fork())==-1)
		{
			printf("childprocess2 failed!");
		}
		else if(pid2==0)
		{			
			c2_addr = (char* )shmat(shmid,0,0);
			cout<<"child2 PID:"<<getpid()<<endl;
			cout<<"child2 received:"<<c2_addr<<endl;
			exit(0);
		}
	//}
	return 0;
}