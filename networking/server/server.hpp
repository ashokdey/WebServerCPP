#ifndef server_hpp
#define server_hpp 

#include "../lib/socket/socket.hpp"
#include "../lib/listening_socket/listening_socket.hpp"
#include "../lib/binding_socket/binding_socket.hpp"

namespace AD 
{
  class Server 
  {
    private:
      ListeningSocket *socket;
      virtual void acceptor() = 0;
      virtual void handler() = 0;
      virtual void responder() = 0;

    public:
      Server(
        int domain, int service, int protocol, int port, u_long interface, int backlog
      );
      virtual void launch() = 0;
      ListeningSocket* getSocket();

  };
}

#endif