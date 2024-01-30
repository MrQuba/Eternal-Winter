#include "File.hpp"

File::File(std::string path)
{
	has_content = true;
	file.open(path, std::ios::in);
	if (!file.good()) std::cout << "error occured while trying to open file" << std::endl;
}

File::~File()
{
	file.close();
}

std::string File::read_whole(std::fstream& file)
{
	std::string result = "";
	while (std::getline(file, line)) {
		result += line;
	}
	return result;
}

std::string File::read_line(std::fstream& file)
{

	if (file.eof()) {
		has_content = false;
		return "...";
	}
	while (std::getline(file, line)) {
		size_t found = line.find("\\n");
		while (found != std::string::npos) {
			line.replace(found, 2, "\n");
			found = line.find("\\n");
		}
		return line;
	}
}

void File::change_file(std::string path)
{
	file.close();
	has_content = true;
	file.open(path, std::ios::in);
	std::string line;
	if (!file.good()) std::cout << "error occured while trying to open file" << std::endl;
}
