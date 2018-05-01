#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <random>

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
	std::mt19937 engine(std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> dis(0,vec.size()-1);
	return vec[dis(engine)];
}

bool isEqual(std::string wordEntry, std::string wordDoc);

bool letterOk(std::string wordEntry, std::string wordDoc, char lettresTrouvees[]);

bool findAll(std::string wordDoc, char lettresTrouvees[]);
