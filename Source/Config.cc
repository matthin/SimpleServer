#include "Config.hh"

#include <fstream>

// Initialize static variables
std::unordered_map<std::string, std::string> ss::Config::sites;

ss::Config::Config() { load_files(); }

void ss::Config::load_files() {
  Json::Reader reader;
  Json::Value root;

  std::ifstream files;
  files.open("../Config/Files.json");
  reader.parse(files, root);

  for (const auto &location : root["files"]) {
    Json::Value file_root;
    std::ifstream file;
    // String literal is for the development environment.
    file.open("../Config/" + location.asString());
    reader.parse(file, file_root);

    parse_file(file_root);
  }
}

void ss::Config::parse_file(const Json::Value &root) {
  for (const auto &block : root) {
    sites[block["Host"].asString()] = block["Location"]["Directory"].asString();
  }
}
