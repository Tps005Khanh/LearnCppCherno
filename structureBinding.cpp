#include <tuple>
#include <string>
#include <iostream>


std::tuple<std::string, int> CreatePerson()
{
	return std::make_tuple("Cherno", 29);
}

int main()
{
	auto person = CreatePerson(); // if we implement like this we can't access name and age except we create tuple or struct for assgin what CreatePerson return

	std::string nameGet = std::get<0>(person);//or we can retrive by index
	int ageGet = std::get<1>(person);

	std::string name;
	int age;
	std::tie(name, age) = CreatePerson();// or we can ue tie to get

	auto[name2,age2] = CreatePerson();//structure binding just use in c++17
}