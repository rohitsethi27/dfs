#include<sys/types.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
//#include "rohitclient1.h"




void rcerecv(int port, char address[10],char *b1)
{
	int s,sock;
	struct sockaddr_in server,client;
	
// create socket
	s=socket(AF_INET,SOCK_STREAM,0);

 // prepare for connect
	server.sin_family=AF_INET;
	server.sin_port=htons(port);
	//serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	server.sin_addr.s_addr=inet_addr(address);

 // connect to echo server
	connect(s,(struct sockaddr *)&server,sizeof(server));

	
	
        	//printf("Enter the command to server\n");
		//fgets(b1,sizeof(b1),stdin);
	//b1="vsrecv";	
	write(s,b1,15);
	
	
	
		

		//strcpy(b1," ");
		//read(s,b1,sizeof(b1));
		//fputs(b1,stdout);
	
	
	close(s);


}
/*void unlinker(int port, char address[10],char *b1)
{
	int s1,sock1;
	char buffer[100];
	struct sockaddr_in server1,client1;
	
// create socket
	s1=socket(AF_INET,SOCK_STREAM,0);

 // prepare for connect
	server1.sin_family=AF_INET;
	server1.sin_port=htons(port);
	//serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	server1.sin_addr.s_addr=inet_addr(address);

 // connect to echo server
	connect(s1,(struct sockaddr *)&server1,sizeof(server1));

	
	
        	//printf("Enter the command to server\n");
		//fgets(b1,sizeof(b1),stdin);
	//b1="vsrecv";	
	write(s1,"unlink",15);
	bzero(b1,sizeof(b1));
	read(s1,buffer,15);
	bzero(buffer,sizeof(buffer));
	write(s1,b1,sizeof(b1));
	
	
		

		//strcpy(b1," ");
		//read(s,b1,sizeof(b1));
		//fputs(b1,stdout);
	
	
	close(s1);


}
*/
int faulttol(int port,char *address)
{
int i;
char buff[50];
int sockfd,len,n;
struct sockaddr_in servaddr;
sockfd=socket(AF_INET,SOCK_DGRAM,0);
if(sockfd==-1)
{
printf("socket creation failed...\n");
exit(0);
}
else
printf("Socket successfully created..\n");
bzero(&servaddr,sizeof(len));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=inet_addr(address);
servaddr.sin_port=htons(port);
len=sizeof(servaddr);
for(i=0;i<2;i++)
{
//printf("\nEnter string : ");
//n=0;
//while((buff[n++]=getchar())!='\n');
strcpy(buff,"iamalive");
sendto(sockfd,buff,sizeof(buff),0,(struct sockaddr *)&servaddr,len);
bzero(buff,sizeof(buff));
//recvfrom(sockfd,buff,sizeof(buff),0,(SA *)&servaddr,&len);
//printf("From Server : %s\n",buff);
//if(strncmp("exit",buff,4)==0)
//{
//printf("Client Exit...\n");
//break;
//}
}
close(sockfd);
}

void main()
{


     	
int k=0,q=0;


char file[20][20];
int pid,pid1;
int counter=0;
char choice[4];
char filename[20];
char filename1[20];
char buffer[10][10];
char buffer1[10][10];
int c1=0,c=0;
a:
bzero(filename,sizeof(filename));
bzero(filename1,sizeof(filename1));
faulttol(5000,"127.0.0.1");
printf("\nwelcome to xyz.com\n");
printf("\nwould you like send or recv\n");
scanf("%s",choice);
if(strcmp(choice,"send")==0)
{
printf("\nplease enter the filename ud like to upload\n");
scanf("%s",filename);


rcerecv(5001,"127.0.0.1","vsrecv");
rcerecv(5002,"127.0.0.1","vsrecv");
printf("\nmulticasting\n");
pid=fork();
if(pid==0)
{sleep(1);
execl("/home/rohit/Desktop/reliableudp/vs_send","./vs_send","127.0.0.1:2001","127.0.0.1:2002",filename,(char *)0);
}
else{
wait(0);kill(0,SIGCHLD);
//invalidate the other clusters

rcerecv(5004,"127.0.0.1",filename);
goto a;
}
/*else if(c>3&&c1<3){
rcerecv(8889,"10.42.0.18","vsrecv");
printf("sending to NNODE");

if(pid==0)
{
execl("/home/rohit/Desktop/rudp/vs_send","./vs_send","10.42.0.18:6889",filename,(char *)0);
}
else{
wait(0);kill(0,SIGCHLD);goto a;
}
*/
}
else if(strcmp(choice,"recv")==0)
{
printf("\nplease enter the filename ud like to download\n");
scanf("%s",filename1);

rcerecv(5004,"127.0.0.1",filename1);
sleep(4);
rcerecv(6003,"127.0.0.1",filename1);

//rcerecv(8880,"127.0.0.1",filename1);

/*pid1=fork();
if(pid1==0)
{

execl("/home/rohit/Desktop/rudp/vs_recv","./vs_recv","7887",(char *)0);

}
else{
kill(0,SIGCHLD);goto a;
}
*/
goto a;
}

}


