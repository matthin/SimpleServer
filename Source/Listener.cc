#include "Listener.hh"

ss::Listener::Listener() { set_timeout(0); }

bool ss::Listener::accept(Socket *socket) {
  socket->handle = ::accept(handle, static_cast<sockaddr *>(nullptr),
                            static_cast<socklen_t *>(nullptr));
}

bool ss::Listener::listen(unsigned short port) {
  auto address = create_address("0.0.0.0", port);
  if (bind(handle, reinterpret_cast<sockaddr *>(&address), sizeof(address)) ==
      0) {
    if (::listen(handle, 0) == 0) {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}
