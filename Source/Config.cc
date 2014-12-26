#include "Config.hh"

#include <fstream>

#include <iostream>

ss::Config::Config()
{
	load_files();
}

void ss::Config::load_files()
{
	Json::Reader reader;
	Json::Value root;

	std::ifstream files;
	files.open("../Config/Files.json");
	reader.parse(files, root);

	for (const auto& location : root["files"])
	{
		Json::Value file_root;
		std::ifstream file;
		// String literal is for the development environment.
		file.open("../Config/" + location.asString());
		reader.parse(file, file_root);

		parse_file(file_root);
	}
}

void ss::Config::parse_file(const Json::Value& root)
{
	for (const auto& block : root["Config"])
	{
		for (const auto& param : block)
		{
			std::cout << param.asString() << std::endl;
		}
	}
}
