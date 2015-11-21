#pragma once

#include <unordered_map>
#include <string>

namespace ss {
namespace http {
class Response {
public:
  std::unordered_map<std::string, std::string> headers;
  std::string message;

  std::string as_string() const;
};
}
}
