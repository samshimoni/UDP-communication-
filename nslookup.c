#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>    
#include <strings.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>    
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>

int main(int argc, char* argv[]) {
  struct addrinfo* res;//define a stuct 
  char* hostname;//define the name of the site 
  char* hostaddr;//define the address of the site
  struct sockaddr_in* saddr;//
  
  if (argc != 2) {
    perror("Usage: hostnamelookup <hostname>\n");
    exit(1);
  }

  hostname = argv[1];//
  
  if (0 != getaddrinfo(hostname, NULL, NULL, &res)) {//condition if the address givven is incorrect.
    fprintf(stderr, "Error in resolving hostname %s\n", hostname);//anwer given to the user.
    exit(1);
  }
  
  saddr = (struct sockaddr_in*)res->ai_addr;
  hostaddr = inet_ntoa(saddr->sin_addr);//retriving the 

  printf("Address for %s is %s\n", hostname, hostaddr);
  
}

