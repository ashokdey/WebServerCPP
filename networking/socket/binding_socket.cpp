#include <iostream>
#include "binding_socket.hpp"

AD::BindingSocket::BindingSocket(
    int domain, int service, int protocol, int port, u_long interface
  ): Socket(domain, service, protocol, port, interface)
{

  int connection = connect_to_network(Socket::get_socket(), Socket::get_address());

  Socket::test_connection(connection);
  Socket::set_connection(connection);
}

int AD::BindingSocket::connect_to_network(int sck, sockaddr_in address)
{
  return bind(sck, (struct sockaddr *)&address, sizeof(address));
}