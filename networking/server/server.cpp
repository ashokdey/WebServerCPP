#include "server.hpp"

AD::Server::Server(
  int domain, int service, int protocol, int port, u_long interface, int backlog
  )
{
  // creating a listener socket 
  socket = new ListeningSocket(
    domain, service, protocol, port, 
    interface, backlog
  );

  // caution: can lead to memoery leak if you reassign socket memeber variable
}

AD::ListeningSocket* AD::Server::getSocket()
{
  return socket;
}
