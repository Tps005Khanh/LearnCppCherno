#include <iostream>
#include <string>
#include <fstream>
#include <optional>

//if we dont use std::optional we can return '' but it look like not good because maybe file is empty one way is use bool is check if stream is open ok

std::optional<std::string> ReadFile(const std::string &_rFileName)
{
	std::ifstream stream(_rFileName);
	if (stream)
	{
		std::string fileContent;
		stream.close();
		return fileContent;
	}
	return {};
}

int main()
{
	std::optional<std::string> fileContent = ReadFile("data.txt");

	if (fileContent.has_value())
	{
		std::cout << "File open successfully\n";
	}
	else {
		std::cout << "File open failed\n";
	}
}