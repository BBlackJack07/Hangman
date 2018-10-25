#ifndef FUNCTIONS_HANGMAN
#define FUNCTIONS_HANGMAN

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

namespace hangman {

	bool wordIsEqual(std::string wordInput, std::string hideWord);

	bool letterIsEqual(std::string wordInput, std::string mot, std::vector<char>& findLetters);

	bool findAll(std::string hideWord, std::vector<char>& findLetters);

	std::string showHideWord(std::string hideWord, std::vector<char>& findLetters);
}

#endif //FUNCTIONS_HANGMAN

