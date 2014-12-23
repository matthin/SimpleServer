#include "Socket.hh"

#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

ss::Socket::Socket()
{
	handle = socket(AF_INET, SOCK_STREAM, 0);
	set_timeout(5);
}

void ss::Socket::send(const std::string& data, unsigned int size)
{
	::send(handle, data.data(), size, 0);
}

void ss::Socket::receive(void* data, const int size, int* received)
{
	int size_received = recv(handle, static_cast<char*>(data), size, 0);
	if (size_received == -1)
	{
		*received = 0;
	}
	else
	{
		*received = size_received;
	}
}

bool ss::Socket::connect(const std::string& host, const unsigned short port)
{
	auto address = create_address(host, port);
	if (::connect(handle, reinterpret_cast<sockaddr*>(&address), sizeof(address)) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ss::Socket::disconnect()
{
	::close(handle);
}

sockaddr_in ss::Socket::create_address(const std::string& host, const unsigned short port)
{
	sockaddr_in address;
	std::memset(&address, 0, sizeof(address));

	inet_pton(AF_INET, host.data(), &(address.sin_addr));
	address.sin_family = AF_INET;
	address.sin_port = htons(port);

	return address;
}

void ss::Socket::set_timeout(const long seconds, const long microseconds)
{
	struct timeval tv;
	tv.tv_sec = seconds;
	tv.tv_usec = microseconds;
	setsockopt(handle, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(struct timeval));
}

void ss::Socket::set_timeout(const long seconds)
{
	set_timeout(seconds, 0);
}

std::string ss::Socket::get_remote_address()
{
	sockaddr_in address;

	socklen_t size = sizeof(address);
	getpeername(handle, reinterpret_cast<sockaddr*>(&address), &size);

	char buffer[INET_ADDRSTRLEN];
	inet_ntop(AF_INET, &address.sin_addr, buffer, sizeof(buffer));

	return std::string(buffer);
}

unsigned short ss::Socket::get_local_port()
{
	sockaddr_in address;
	socklen_t size = sizeof(address);

	getsockname(handle, reinterpret_cast<sockaddr*>(&address), &size);

	return ntohs(address.sin_port);
}
