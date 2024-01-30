#include <fstream>
#include <iostream>
#include <string>
#pragma once

class File {
public:
	std::fstream file;

	File(std::string path);
	~File();
	std::string read_whole(std::fstream& file);
	std::string read_line(std::fstream& file);
	void change_file(std::string path);
	bool has_content = true;
	std::string line = "";
};