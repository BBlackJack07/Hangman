#ifndef MY_VECTOR_FUNCS
#define MY_VECTOR_FUNCS

#include <vector>
#include <fstream>
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
T selectRandomInVector(std::vector<T> vec)
{
	std::mt19937 engine(std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> dis(0,vec.size()-1);
	return vec[dis(engine)];
}
#endif //MY_VECTOR_FUNCS