#include "Server.hh"

#include "Client.hh"
#include "Config.hh"
#include <memory>
#include <thread>
#include <iostream>

ss::Server::Server(const unsigned short port) : listener() {
  Config config;

  listener.listen(port);
  if (listener.getLocalPort() == 0) {
    std::cout << "Listener could not attach port: " << port << std::endl;
    exit(1);
  }

  while (true) {
    auto *socket = new rokunet::Socket;

    if (listener.accept(socket)) {
      new std::thread([socket]() { Client client(socket); });
    }
  }
}
