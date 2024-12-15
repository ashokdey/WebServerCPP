#ifndef BindingSocket_hpp
#define BindingSocket_hpp

#include <stdio.h>

#include "socket.hpp"

namespace AD {
  class BindingSocket: public Socket {
    public:
    BindingSocket(int domain, int service, int protocol, int port, u_long interface);
    int connect_to_network(int sck, struct sockaddr_in address);
  };
}

#endif