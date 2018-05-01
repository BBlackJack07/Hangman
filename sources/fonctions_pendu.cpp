#include "fonctions_pendu.h"


bool isEqual(std::string wordEntry, std::string wordDoc)
{
	std::string word1 { wordEntry };
	std::string word2 {  wordDoc  };
	std::transform(word1.begin(), word1.end(), word1.begin(), ::toupper);
	std::transform(word2.begin(), word2.end(), word2.begin(), ::toupper);
	return word1 == word2;
}

bool letterOk(std::string wordEntry, std::string wordDoc, char lettresTrouvees[])
{
	bool letterIsOk { false };
	for(unsigned int i {0}; i < wordDoc.size(); ++i)
	{
		if(toupper(wordEntry[0]) == toupper(wordDoc[i]))
		{
			lettresTrouvees[i] = wordDoc[i];
			
			letterIsOk = true;
		}















	}
	return letterIsOk;
}

bool findAll(std::string wordDoc, char lettresTrouvees[])
{
	for(unsigned short i {0}; i < wordDoc.size(); ++i)
	{
		if(toupper(wordDoc[i]) != toupper(lettresTrouvees[i]))
		{
			return false;
		}
	}
	return true;
}

std::string showHideWord(std::string wordDoc, char lettresTrouvees[])
{
	std::string hideWord {};

	for(unsigned int i {0}; i < wordDoc.size(); ++i)
	{
		if(toupper(lettresTrouvees[i]) == toupper(wordDoc[i]))
		{
			hideWord += wordDoc[i];
			hideWord += " ";
		}
		else
		{
			hideWord += "_ ";
		}
	}
	return hideWord;
}

