#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>

template<typename T>
std::vector<T>& operator<<(std::vector<T>& vec, std::ifstream& doc)
{
	T line {};
	while(getline(doc, line))
	{
		vec.push_back(line);
	}
	return vec;
}

template<typename T>
T randomVector(std::vector<T> vec)
{
	std::uniform_int_distribution<unsigned int> dis(0, vec.size() - 1);
	auto const seed = std::time(nullptr);
	std::default_random_engine engine { seed };
	return vec[dis(engine)];
}

bool isEqual(std::string wordEntry, std::string wordDoc);

bool isEqual(std::string wordEntry, std::string wordDoc, char lettresTrouvees[]);
