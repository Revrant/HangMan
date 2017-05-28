#ifndef HANGMAN_H
#define HANGMAN_H
#include <string>

class Hangman
{
private://variables
  std::string secretWord;
  char* disguisedWord;
  int disguisedWordSize;
  int guessCount;
  int missesCount;
  int MAX_MISSES_ALLOWED;
  char* missedMarkers;

public:
  Hangman(std::string word);//Constructor
  ~Hangman();//Deconstructor
  bool guessCharacter(char c);
  bool isGameOver();
  bool isFound();
  std::string getDisguisedWord();
  int getGuessCount();
  int getMissesCount();
  std::string getMissedMarker();
};
#endif
