#include "pendu.h"

int main()
{
	std::cout << " Bonjour,\n Bienvenue dans le Jeu du Pendu !\n Règles : \n  - Vous avez dix vies.\n  - Ecrivez tous les mots et lettres sans accents.\n" << std::endl;   
	std::ifstream doc("./wordlist");
	if(doc)
	{
		std::vector<std::string> wordList {};
		wordList << doc;
		doc.close();
		bool replay { true };
		
		do
		{
			const std::string mot { randomVector(wordList) };
			for(unsigned int i {0}; i < mot.size(); ++i)
				std::cout << "_ ";
			std::cout << std::endl << std::endl;
			bool win { false };
			unsigned short int life { 10 };
			char lettresTrouvees[mot.size()];
			while(life > 0 && !win)
			{
				std::cout << "Entrez une lettre ou un mot : ";
				std::string wordInput {};
				std::cin >> wordInput;
				std::cout << std::endl;
				if(isEqual(wordInput, mot))
				{ 	
					std::cout << " Génial ! Vous avez trouvé le mot !" << std::endl << std::endl;
					win = true;
				}
				else if(letterOk(wordInput, mot, lettresTrouvees))
				{
					std::cout << " Bien joué, vous avez trouvé une lettre ! " << std::endl << std::endl;
				}
				else
				{
					life--;
					std::cout << " Zut... vous vous êtes trompé. Il vous reste " << life << " vies." << std::endl << std::endl;
				}
				
			}
			
			if(!win)
			{
				std::cout << " Dommage, vous avez perdu. Le mot était : " << mot << std::endl;
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

