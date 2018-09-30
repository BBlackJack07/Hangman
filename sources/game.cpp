#include "functions_hangman.h"
#include <thread>

int main()
{
	using namespace std::chrono_literals;
	std::cout << " Bonjour,\n Bienvenue dans le Jeu du Pendu !" << std::endl;;
	std::this_thread::sleep_for(1000ms);
	std::cout << " Règles : " << std::endl; 
	std::this_thread::sleep_for(1000ms);
	std::cout << " - Vous avez dix vies." << std::endl;
	std::this_thread::sleep_for(1000ms);
	std::cout << " - Ecrivez tous les mots et lettres sans accents.\n" << std::endl;
	std::this_thread::sleep_for(1000ms);
	std::ifstream doc("./wordlist");
	if(doc)
	{
		std::vector<std::string> wordList {};
		{
			using namespace hangman;
			wordList << doc;
		}
		doc.close();
		bool replay { true };

		do
		{
			const std::string  hideWord    { hangman::randomVector(wordList) };
			bool               win         { false };
			unsigned short int life        { 10 };
			unsigned int       round       { 1 };
			std::vector<char>  findLetters(hideWord.size());

			while(life > 0 && !win)
			{
				std::cout << "\n\n\n" << "----------Round " << round << "----------" << std::endl;
				std::cout << " " << hangman::showHideWord(hideWord, findLetters) << std::endl << std::endl;
				std::cout << " Entrez une lettre ou un mot : ";
				std::string wordInput {};
				std::cin >> wordInput;
				if(hangman::wordIsEqual(wordInput, hideWord))
				{
					std::cout << " Génial ! Vous avez trouvé le mot !" << std::endl;
					win = true;
				}	
				else if(wordInput.size() == 1 && hangman::letterIsEqual(wordInput, hideWord, findLetters))
				{
					std::cout << " Bien joué, vous avez trouvé une lettre ! " << std::endl;
					if(hangman::findAll(hideWord, findLetters))
					{
						std::cout << " Génial ! Vous avez trouvé le mot ( " << hideWord  << " ) !" << std::endl;
						win = true;
					}
				}
				else
				{
					life--;
					//showPendu(life);
					std::cout << " Zut... vous vous êtes trompé. Il vous reste " << life << " vies." << std::endl;
				}
				std::this_thread::sleep_for(1500ms);
				round++;
				std::cout << "--------------------" << std::endl;

			}

			if(!win)
			{
				std::cout << " Dommage, vous avez perdu. Le mot était : " << hideWord << std::endl;
			}
			else
			{
				std::cout << " Vous avez gagné !" << std::endl;
			}

			std::cout << " Voulez-vous rejouer ? (o/n)" << std::endl;
			std::string r {};
			std::cin >> r;
			switch(r[0])
			{
				case 'o':
					std::cout << " Cool !" << std::endl;
					break;
				case 'n':
					std::cout << " Au revoir !" << std::endl;
					replay = false;
					break;
			}

		}while(replay);

	}
	else
	{
		std::cout << "Erreur lors de l'ouverture du fichier." << std::endl;
	}

	return 0;
}

