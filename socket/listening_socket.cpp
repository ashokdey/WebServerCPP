#include "listening_socket.hpp"
#include "binding_socket.hpp"
#include "socket.hpp"

AD::ListeningSocket::ListeningSocket(int domain, int service, int protocol, int port, u_long interface, int backlog):
BindingSocket(domain, service, protocol, port, interface) 
{
  this->backlog = backlog;
}

void AD::ListeningSocket::start_listening()
{
  listening = listen(get_connection(), backlog); 
}
