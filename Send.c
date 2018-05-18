#include <sys/types.h>
#include <netinet/in.h>
#include <inttypes.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	int fsize;
  int socket_fd;//if the value is -1 - failed 
  struct sockaddr_in  dest,from;//contains the ip, socket information 
  struct hostent *hostptr;
  //struct { char head; u_long body; char tail; } msgbuf;// creats a strucket named msgbuf and gets the head,tail and body.
char name[100]="Samuel";

  socket_fd = socket (AF_INET, SOCK_DGRAM, 0);//creating socket (v4/v6,udp,zero)
  memset((char *) &dest,0, sizeof(dest)); //resting the struckt to zero
  hostptr = gethostbyname(argv[1]);//recieving ip
  dest.sin_family = (short) AF_INET;//v4orv6
  memcpy(hostptr->h_addr, (char *)&dest.sin_addr,hostptr->h_length);//copping the ip from sin_addr to 	h_addr
  dest.sin_port = htons((u_short)0x3333);////converts the port to network byte

  //msgbuf.head = '<';//
  //msgbuf.body = htonl(getpid()); /* IMPORTANT! */
  //msgbuf.tail = '>';

  sendto(socket_fd,name,100,0,(struct sockaddr *)&dest,
                  sizeof(dest));//send the final meggage
	fsize=sizeof(from);	
	bzero(name,100);
	recvfrom(socket_fd,name,100,0,(struct sockaddr *)&from,&fsize);
	
	 printf("Got data ::%s\n",name); //request print
         fflush(stdout);//cleans the memory



  return 0;
}

