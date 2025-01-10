#ifndef BindingSocket_hpp
#define BindingSocket_hpp

#include <stdio.h>

#include "../socket/socket.hpp"

namespace AD {
  class BindingSocket: public Socket 
  {
    private:
      int binding;
      void connect_to_network(int socket, struct sockaddr_in address);
    public:
      BindingSocket(int domain, int service, int protocol, int port, u_long interface);
      int get_binding();
  };
}

#endif