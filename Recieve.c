#include <sys/types.h>
#include <netinet/in.h>
#include <inttypes.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


void printsin(struct sockaddr_in *sin, char *pname, char* msg){
	char *ip = inet_ntoa(sin->sin_addr);
	puts(pname);
	printf("UDP-SERVER:\n");
	printf("%s ip= %s, port= %d \n",msg,ip,sin->sin_port); 
}



int main(int argc, char *argv[])
{
   
  char nameServer[50]  ="Chemouny";	
  int socket_fd,fsize;
  struct sockaddr_in  s_in, from;
  struct { char head; u_long  body; char tail;} msg;

  socket_fd = socket (AF_INET, SOCK_DGRAM, 0);// create a socket with IPV4 UDP protocol with the value zero.

  memset((char *) &s_in,0, sizeof(s_in));  // fill all the s-in with zeros.

  s_in.sin_family = (short)AF_INET;//kind of port ipv4
  s_in.sin_addr.s_addr = htonl(INADDR_ANY);    //convert ip adddres to network byte.
  s_in.sin_port = htons((u_short)0x3333);//converts the port number  to network byte.

  	printsin( &s_in, "RECV_UDP", "Local socket is:"); 
 	fflush(stdout);

  bind(socket_fd, (struct sockaddr *)&s_in, sizeof(s_in));//conects the port and the address
	char name[100];
	
  while(1) {
    fsize = sizeof(from);//get the length of the struct 'from'
    //cc = recvfrom(socket_fd,&msg,sizeof(msg),0,(struct sockaddr *)&from,&fsize);
	recvfrom(socket_fd,name,100,0,(struct sockaddr *)&from,&fsize);
    printsin( &from, "recv_udp: ", "Packet from:");
    printf("Got data ::%s\n",name); //request print
    fflush(stdout);//cleans the memory
	sendto(socket_fd,nameServer,50,0,(struct sockaddr *)&from,sizeof(from)); 

  }
	
printf("%lu",msg.body);
  
  return 0;
}


