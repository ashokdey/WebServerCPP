#include "socket.hpp"
#include <stdlib.h>

AD::Socket::Socket(int domain, int service, int protocol, int port, u_long interface)
{
  // define the address struct 
  address.sin_family = domain;
  address.sin_port = htons(port); 
  address.sin_addr.s_addr = htonl(interface);

  // make the connection
  sck = socket(domain, service, protocol);
  test_connection(sck);
  
}

void AD::Socket::test_connection(int entity)
{
  if (entity < 0) 
  {
    perror("Failed to connect");
    exit(EXIT_FAILURE);
  }
}

struct sockaddr_in AD::Socket::get_address() 
{
  return address;
}

int AD::Socket::get_socket() 
{
  return sck;
}

