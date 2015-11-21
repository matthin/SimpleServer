#pragma once

#include <string>
#include "http/Request.hh"
#include "http/Response.hh"

namespace ss {
namespace methods {
class Get {
public:
  Get(const http::Request &request, http::Response *response);

private:
  const http::Request &request;

  std::string mime_type(const std::string &location);
  std::string read_file(const std::string &location);

  void create_correct_location();
  std::string correct_location;
};
}
}
