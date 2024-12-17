#ifndef ListeningSocket_hpp
#define ListeningSocket_hpp

#include "socket.hpp"
#include "binding_socket.hpp"

namespace AD 
{
  class ListeningSocket: public BindingSocket
  {
    private:
      int backlog;
      int listening;

    public: 
      ListeningSocket(
        int domain, int service, int protocol, 
        int port, u_long interface, int backlog
        );

      void start_listening();
  };
}

#endif