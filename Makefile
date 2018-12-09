.PHONY: uninstall

.SUFFIXES:

all : sources/*.cpp headers/*.hpp
	g++ sources/*.cpp -I headers -Wall -Wextra -pedantic -o pendu.out -std=c++17

debug : sources/*.cpp headers/*.hpp
	g++ sources/*.cpp -I headers -Wall -Wextra -pedantic -g -o pendu.out -std=c++17

install : all
	mkdir ../jeu_du_pendu
	cp pendu.out ../jeu_du_pendu
	cp wordlist ../jeu_du_pendu
	echo 'Jeu du Pendu installé dans le répertoire ../jeu_du_pendu'

uninstall :
	rm -rvf ../jeu_du_pendu/

