#include <iostream>
#include "binding_socket.hpp"

AD::BindingSocket::BindingSocket(
    int domain, int service, int protocol, int port, u_long interface
  ): Socket(domain, service, protocol, port, interface)
{
  connect_to_network(Socket::get_socket(), Socket::get_address());
}

int AD::BindingSocket::get_binding()
{
  return binding;
}

void AD::BindingSocket::connect_to_network(int sck, sockaddr_in address)
{
  binding = bind(sck, (struct sockaddr *)&address, sizeof(address));
}