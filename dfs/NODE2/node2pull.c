#include<signal.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define BUFSIZE 1000

void main()

{
	
	
	int reqd;
	int pid,pid1;
	int port =6002;
	char choice[2];
int s,n,sock,fd;
	//fd = open("some",O_RDWR);
	struct sockaddr_in client,server;
	char b1[100]=" ",b2[100]=" ";
	//char c[20] = " >> some";
	int on=1;
	  
 
	

	/*printf("\nwelcome to RNODE would u like to start it up.. (y?n)\n");
	gets(choice);
	if(strcmp(choice,"n")==0){exit(0);}
	else if(strcmp(choice,"y")==0)
{*/	
	
// create socket
	
	
pid =fork();
if(pid==0){	
	
	s=socket(AF_INET,SOCK_STREAM,0);

      //printf("setsockopt(SO_REUSEADDR)\n");
      if (setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
        {
          perror("setsockopt(SO_REUSEADDR) failed");
        }
	
// prepare for bind
	server.sin_family=AF_INET;
	server.sin_port=htons(port);
	server.sin_addr.s_addr=inet_addr("127.0.0.1");

// bind
	
	if((bind(s,(struct sockaddr *)&server,sizeof(server)))==-1)
	{
          printf("bind error");
          return ;
    }	
	
	 
	 
	
	//for(i=0;i<1000;i++){
// listen only 1 queue
	listen(s,1);
	printf("\n Server ready");
	printf("\nup and running\n");
	printf("\nwaiting for command\n");
	
    n=sizeof(client);
// accept only 1 client
	sock= accept(s,(struct sockaddr *)&client,&n);
	

// read and write until ^D (from client)
	
	 
	     recv(sock,b1,sizeof(b1),0);

		
}

 //b1 = strcat((char *)b1,c);
  
else{ wait();

		close(sock);
	close(s);
	}

pid1=fork();
if(pid1==0);
else{wait();
close(sock);
	close(s);
	    


	
/*
  if (pipe(pfd) < 0) {
    printf("Oups, pipe failed.  Exiting\n");
    exit(-1);
  }

  n = fork();

  if (n < 0) {
    printf("Oups, fork failed.  Exiting\n");
    exit(-2);
  } else if (n == 0) {
    close(pfd[0]);

    dup2(pfd[1], 1);
    close(pfd[1]);

    execlp("find", "find", b1, (char *) 0);
    printf("Oups, execlp failed.  Exiting\n");  //This will be read by the  parent. 
    exit(-1); // To avoid problem if execlp fails, especially if in a loop. 
  } else {
    close(pfd[1]);

    while ((n = read(pfd[0], str, BUFSIZE)) > 0) {
      str[n] = '\0';
      printf("%s", str);
    }

    close(pfd[0]);
    wait(&n); // To avoid the zombie process. /
    if (n != 0) {
       printf("Oups, find or execlp failed.\n");
    }
  }
}*/
	execl("/home/rohit/Desktop/rudp1/vs_send","./vs_send","127.0.0.1:4001",b1,(char *)0);

		//send(3,"127.0.0.1:7887", b1, (char *)0)
	     read(1,b2,sizeof(b2));
	     //fgets(b1,sizeof(b1),stdout);
	     send(sock,b1,sizeof(b1),0);
	     //if(strcmp(b1,"end")==0)
             //break;
		//printf("\n Client:%s",b1);
		//printf("\n Server:");
		//gets(b2);
		//send(sock,b1,sizeof(b1),0); 
        //if(strcmp(b1,"end")==0)
          //   break;      // write to client*/
	

// close connection from client and stop echo server
	close(sock);
	close(s);
	return ;
}	

	
	}
	
	
		
	
	
	


