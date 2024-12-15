#include "socket.hpp"

AD::Socket::Socket(int domain, int service, int protocol, int port, u_long interface)
{
  // define the address struct 
  address.sin = domain;
  address.sin_port = htons(port); 
  address.sin_addr.s_addr = htonl(interface);

  // make the connection
  int sck = socket(domain, service, protocol);
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

int AD::Socket::get_connection() 
{
  return connection;
}

void AD::Socket::set_connection(int connection)
{
  this->connection = connection;
}
