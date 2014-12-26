#include "Server.hh"

#include "Socket.hh"
#include "Client.hh"
#include "Config.hh"
#include <memory>
#include <thread>

ss::Server::Server(const unsigned short port) : listener()
{
	Config config;

	listener.listen(port);

	/*while (true) {
		Socket* socket = new Socket;
		
		if (listener.accept(socket))
		{
			new std::thread([socket]()
			{
				Client client(socket);
			});
		}
	}*/
}
