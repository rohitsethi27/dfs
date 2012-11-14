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
#include<fcntl.h>
#include<arpa/inet.h>
//#include "trialserver.h"

void rcerecv(int port, char address[10],char *b1)
{
	int s1,sock1;
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
	write(s1,b1,15);
	
	
	
		

		//strcpy(b1," ");
		//read(s,b1,sizeof(b1));
		//fputs(b1,stdout);
	
	
	close(s1);


}
void main()
{
	int fd;
	int i;	
	int pid;
	int k=0;
	//char removelist[100][20];
	int on=1;
	int unl;
	char pathname[30];
	int s,n,sock;
	struct sockaddr_in client,server;
	char b1[100]=" ",b2[100]=" ";
	strcpy(	pathname,"/home/rohit/Desktop/NODE3/");
	a:

	printf("\nwelcome to RNODE start it up.. \n");
	
	s=socket(AF_INET,SOCK_STREAM,0);
	
	if (setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
        {
          perror("setsockopt(SO_REUSEADDR) failed");
        }
	

	server.sin_family=AF_INET;
	server.sin_port=htons(5004);
	server.sin_addr.s_addr=htonl(INADDR_ANY);

	if((bind(s,(struct sockaddr *)&server,sizeof(server)))==-1)
	{
          printf("bind error");
          return ;
    }


	listen(s,1);
	printf("\n Server ready");
	printf("\nup and running\n");
	printf("\nwaiting for command\n");
	
        n=sizeof(client);

	sock = accept(s,(struct sockaddr *)&client,&n);
	
	
		bzero(b1,sizeof(b1));
	        recv(sock,b1,sizeof(b1),0);
	
	/*	while(i<100)
		{
		if(strcmp(removelist[i++][20],b1)==0)
		{	rcerecv(7001,"127.0.0.1",b1);
			rcerecv(7002,"127.0.0.1",b1);
			break;
			
		}
		}
	
	
	   	strcpy(removelist[k++][20],b1);*/

		strcat(pathname,b1);
		unlink(pathname);
		remove(pathname);
		rcerecv(7001,"127.0.0.1",b1);
	        rcerecv(7002,"127.0.0.1",b1);
		
	
	


system(b1);
		
		


	/*pid = fork();
	if(pid==0){
	execl("/home/rohit/Desktop/rudp1/vs_recv","./vs_recv","2003",(char *)0);
	
}
else{
wait(0);
kill(0,SIGCHLD);


	

}*/
	
	close(sock);
	close(s);
	close(fd);
	
	return ;
	
	

	
}	
	
	
		
	
	
	


