#include "Get.hh"

#include <fstream>
#include <unordered_map>
#include "Config.hh"

ss::methods::Get::Get(const rokunet::Http::Request &request,
                      rokunet::Http::Response::Builder *responseBuilder)
    : request(request) {
  std::unordered_map<std::string, std::string> responseHeaders;

  create_correct_location();
  auto file = read_file(correct_location);
  if (file.empty()) {
    responseBuilder->setCode(404);
    responseBuilder->setCodeMessage("Not Found");
    responseHeaders["Content-Length:"] = 15;
    responseBuilder->setBody("404 - Not Found");
  } else {
    responseHeaders["Content-Type"] = mime_type(correct_location);
    responseBuilder->setCode(200);
    responseBuilder->setCodeMessage("OK");
    responseHeaders["Content-Length:"] = file.size();
    responseBuilder->setBody(file);
  }
}

std::string ss::methods::Get::mime_type(const std::string &location) {
  auto split_pos = location.find_last_of('.');
  if (split_pos == std::string::npos) {
    return "text/plain";
  } else {
    auto extention = location.substr(split_pos + 1);

    // For testing purposes
    if (extention == "cc") {
      return "text/html";
    } else {
      return "text/plain";
    }
  }
}

std::string ss::methods::Get::read_file(const std::string &location) {
  std::ifstream file(location);
  if (!file.is_open()) {
    return "";
  }

  file.seekg(0, std::ios::end);
  auto size = file.tellg();
  std::string contents(static_cast<unsigned int>(size), ' ');
  file.seekg(0, std::ios::beg);
  file.read(&contents[0], size);

  return contents;
}

void ss::methods::Get::create_correct_location() {
  const auto host = request.headers.at("Host");

  std::string req_location;
  if (request.location.back() == '/') {
    // Using Makefile just for testing purposes
    req_location = request.location.substr(1) + "Makefile";
  } else {
    req_location = request.location.substr(1);
  }

  // Check if Host header contains a port.
  const auto port_pos = host.find_last_of(":");
  if (port_pos == std::string::npos) {
    correct_location = (Config::get_sites()[host] + req_location);
  } else {
    correct_location =
        (Config::get_sites()[host.substr(0, port_pos)] + req_location);
  }
}
