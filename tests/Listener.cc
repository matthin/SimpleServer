#include "catch.hpp"

#include "Listener.hh"
#include "Socket.hh"

TEST_CASE("Listens on selected port")
{
	ss::Listener listener;
	listener.listen(8080);

	REQUIRE(listener.get_local_port() == 8080);
}

TEST_CASE("Accepts new clients")
{
	ss::Listener listener;
	listener.listen(8080);

	ss::Socket socket;
	socket.connect("127.0.0.1", 8080);

	listener.accept(&socket);

	REQUIRE(socket.get_local_port() != 0);
}
