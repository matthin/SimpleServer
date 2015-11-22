#pragma once

#include <rokunet/Http/Request.h>
#include <rokunet/Http/Response.h>
#include <string>

namespace ss {
namespace methods {
class Get {
public:
  Get(const rokunet::Http::Request &request,
      rokunet::Http::Response::Builder *responseBuilder);

private:
  const rokunet::Http::Request &request;

  std::string mime_type(const std::string &location);
  std::string read_file(const std::string &location);

  void create_correct_location();
  std::string correct_location;
};
}
}
