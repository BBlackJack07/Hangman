#include "fonctions_pendu.h"


bool hangman::wordIsEqual(std::string wordInput, std::string hideWord)
{
	std::string word1 { wordInput };
	std::string word2 {  hideWord  };
	std::transform(word1.begin(), word1.end(), word1.begin(), ::toupper);
	std::transform(word2.begin(), word2.end(), word2.begin(), ::toupper);
	return word1 == word2;
}

bool hangman::letterIsEqual(std::string wordInput, std::string hideWord, std::vector<char>& findLetters)
{
	bool letterEqual { false };
	for(unsigned short int i {0}; i < hideWord.size(); ++i)
	{
		if(toupper(wordInput[0]) == toupper(hideWord[i]))
		{
			findLetters[i] = hideWord[i];
			
			letterEqual = true;
		}
	}
	return letterEqual;
}

bool hangman::findAll(std::string hideWord, std::vector<char>& findLetters)
{
	for(unsigned short int i {0}; i < hideWord.size(); ++i)
	{
		if(toupper(hideWord[i]) != toupper(findLetters[i]))
		{
			return false;
		}
	}
	return true;
}

std::string hangman::showHideWord(std::string hideWord, std::vector<char>& findLetters)
{
	std::string showWord {};

	for(unsigned int i {0}; i < hideWord.size(); ++i)
	{
		if(toupper(findLetters[i]) == toupper(hideWord[i]))
		{
			showWord += hideWord[i];
			showWord += " ";
		}
		else
		{
			showWord += "_ ";
		}
	}
	return showWord;
}

