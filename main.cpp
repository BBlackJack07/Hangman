#include "pendu.h"

using namespace std;

int main()
{
	fstream doc("./dico");
	if(doc)
	{
		vector<string> wordList {};
		wordList << doc;
		doc.close();
		bool replay { true };
		
		do
		{
			const string mot { randomVector(wordList) };
		}while(replay);
		
	}
	else
	{
		cout << "Erreur lors de l'ouverture du fichier." << endl;
	}
