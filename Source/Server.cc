#include "Server.hh"

#include "Socket.hh"
#include "Client.hh"
#include <memory>
#include <thread>

#include <iostream>

ss::Server::Server(const unsigned short port) : listener()
{
	listener.listen(port);

	while (true) {
		Socket* socket = new Socket;
		
		if (listener.accept(socket))
		{
			new std::thread([socket]()
			{
				Client client(socket);
			});
		}
	}
}
