all : sources/*.cpp headers/*.h
	g++ sources/*.cpp headers/*.h -I headers -o pendu.out -std=c++17

install : all
	mkdir ../jeu_du_pendu
	cp pendu.out ../jeu_du_pendu
	cp wordlist ../jeu_du_pendu
	echo 'Jeu Du Pendu installé dans le répertoire ../jeu_du_pendu'

uninstall : 
	rm -rvf ..jeu_du_pendu/
