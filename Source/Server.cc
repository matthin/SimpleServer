#include "Server.hh"

#include "Socket.hh"
#include "Client.hh"
#include "Config.hh"
#include <memory>
#include <thread>
#include <iostream>

ss::Server::Server(const unsigned short port) : listener()
{
	Config config;

	listener.listen(port);
	if (listener.get_local_port() == 0)
	{
		std::cout << "Listener could not attach port: " << port << std::endl;
		exit(1);
	}

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
