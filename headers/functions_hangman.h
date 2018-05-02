#ifndef FUNCTIONS_HANGMAN
#define FUNCTIONS_HANGMAN

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <random>

namespace hangman {

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

	bool wordIsEqual(std::string wordInput, std::string hideWord);

	bool letterIsEqual(std::string wordInput, std::string mot, std::vector<char>& findLetters);

	bool findAll(std::string hideWord, std::vector<char>& findLetters);

	std::string showHideWord(std::string hideWord, std::vector<char>& findLetters);
}

#endif //FUNCTIONS_HANGMAN

