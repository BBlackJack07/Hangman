#include "pendu.h"


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
		if(toupper(wordEntry[0]) == wordDoc[i])
		{
			std::cout << wordDoc[i] << " ";
			lettresTrouvees[i] = wordDoc[i];
			return true;
		}
		else if(lettresTrouvees[i] == wordDoc[i])
		{
			std::cout << wordDoc[i] << " ";
		}
		else
			std::cout << "_ ";
	}
	return letterIsOk;
}
