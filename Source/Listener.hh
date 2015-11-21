#pragma once

#include "Socket.hh"

namespace ss {
class Listener : public Socket {
public:
  Listener();

  bool accept(Socket *socket);
  bool listen(unsigned short port);
};
}
