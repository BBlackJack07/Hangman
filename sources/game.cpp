#include "fonctions_pendu.h"
#include <thread>

int main()
{
	using namespace std::chrono_literals;
	std::cout << " Bonjour,\n Bienvenue dans le Jeu du Pendu !\n Règles : \n  - Vous avez dix vies.\n  - Ecrivez tous les mots et lettres sans accents.\n" << std::endl;
	std::this_thread::sleep_for(2000ms);
	std::ifstream doc("./wordlist");
	if(doc)
	{
		std::vector<std::string> wordList {};
		wordList << doc;
		doc.close();
		bool replay { true };

		do
		{
			const std::string  mot   { randomVector(wordList) };
			bool               win   { false };
			unsigned short int life  { 10 };
			char               lettresTrouvees[mot.size()];
			unsigned int       round { 1 };

			while(life > 0 && !win)
			{
				std::cout << "\n\n\n" << "----------Round " << round << "----------" << std::endl;
				std::cout << " " << showHideWord(mot, lettresTrouvees) << std::endl << std::endl;
				std::cout << " Entrez une lettre ou un mot : ";
				std::string wordInput {};
				std::cin >> wordInput;
				if(isEqual(wordInput, mot))
				{
					std::cout << " Génial ! Vous avez trouvé le mot !" << std::endl;
					win = true;
				}	
				else if(wordInput.size() == 1 && letterOk(wordInput, mot, lettresTrouvees))
				{
					std::cout << " Bien joué, vous avez trouvé une lettre ! " << std::endl;
					if(findAll(mot, lettresTrouvees))
					{
						std::cout << " Génial ! Vous avez trouvé le mot !" << std::endl;
						win = true;
					}
				}
				else
				{
					life--;
					//showPendu(life);
					std::cout << " Zut... vous vous êtes trompé. Il vous reste " << life << " vies." << std::endl;
				}
				std::this_thread::sleep_for(2000ms);
				round++;
				std::cout << "--------------------" << std::endl;

			}

			if(!win)
			{
				std::cout << " Dommage, vous avez perdu. Le mot était : " << mot << std::endl;
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

