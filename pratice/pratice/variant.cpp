#include<iostream>
#include<variant>
#include<optional>

enum class ErrorCode
{
	None = 0, NotFound = 1, NoAccess = 2
};

std::optional<std::string>ReadFileAsString()
{
	return {};
}

int main()
{
	std::variant<std::string, int>data;
	data = "Cherno";
	  

	std::cout << std::get<std::string>(data) << "\n";
	if (auto value = std::get_if<std::string>(&data))
	{
		std::string& v = *value;
	}

	std::cout<<std::get<std::string>(data)<<"\n";
	std::cout << std::get<int>(data) << "\n";

	std::cin.get();

}