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


void main()
{
	int fd;
	int pid;
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
	server.sin_port=htons(5003);
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
	if(strcmp(b1,"unlink")==0)
	{
		bzero(b1,sizeof(b1));		
		send(sock,"filerequest",sizeof("filerequest"),0);
		recv(sock,b1,sizeof(b1),0);    
		printf("\n%s\n",b1);    
		strcat(pathname,b1);
		unl=unlink(pathname);
		
	}	
	
	

system(b1);
		
		


	pid = fork();
	if(pid==0){
	execl("/home/rohit/Desktop/rudp1/vs_recv","./vs_recv","2003",(char *)0);
	
}
else{
wait(0);
kill(0,SIGCHLD);


	

}

	close(sock);
	close(s);
	close(fd);
	goto a;
	return ;
	
	

	
}	
	
	
		
	
	
	


