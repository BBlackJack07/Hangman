#ifndef HANGMAN
#define HANGMAN

#include <algorithm>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include "vector.hpp"


class Hangman
{
    public:
        Hangman(std::string path_to_wordlist);
        void start_game();
	    bool wordsAreEqual(std::string inputWord);
	    bool letterIsInWord(std::string inputWord);
	    bool isWordFound();
	    std::string showWord();
        std::string drawHangman();

    private:
        std::vector<char> foundLetters;
        std::string word;
        unsigned short int errors;
        std::vector<std::string> wordlist;
        bool win;
};

#endif //HANGMAN

