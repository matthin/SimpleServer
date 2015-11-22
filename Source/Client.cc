#include "Client.hh"

#include <rokunet/Http/Request.h>
#include <rokunet/Http/Response.h>
#include <string>
#include <sstream>
#include "methods/Get.hh"
#include "Config.hh"

ss::Client::Client(rokunet::Socket *socket) : socket(socket) {
  auto request = get_request();
  rokunet::Http::Response::Builder responseBuilder;

  switch (request.method) {
  case rokunet::Http::Request::Method::Get:
    methods::Get(request, &responseBuilder);
    break;
  default:
    break;
  }

  socket->send(responseBuilder.build().prepare());
}

rokunet::Http::Request ss::Client::get_request() {
  std::ostringstream response;

  for (int i = 1; i < 11; ++i) {
    response << socket->receive(1024);
    if (response.str().size() / i != 1024) {
      break;
    }
  }

  return rokunet::Http::Request::Factory(response.str()).build();
}
