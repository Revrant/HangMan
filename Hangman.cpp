#include "Hangman.h"
#include <iostream>
#include <string>

/*-------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------*/
Hangman::Hangman(std::string word)
{
  //Declares all variables for File
  secretWord = word;
  MAX_MISSES_ALLOWED = 7;
  disguisedWord = new char[secretWord.length()];
  disguisedWordSize = secretWord.length();
  guessCount = -1;
  missesCount = 0;

  //Creats the "secret" word
  for(int i = 0; i < disguisedWordSize; i++)
  {
    if(secretWord.at(i) == ' ')
    {
      disguisedWord[i] = ' ';
    }
    else
    {
    disguisedWord[i] = '?';
    }
  }
  //Creates misses marks
  missedMarkers = new char[MAX_MISSES_ALLOWED];

  for(int i = 0; i < MAX_MISSES_ALLOWED; i++)
  {
    missedMarkers[i] = 'O';
  }
}
/*-------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------*/
Hangman::~Hangman()
{
  //Deconstructor
  delete[] disguisedWord;
  delete[] missedMarkers;
}
/*-------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------*/
bool Hangman::guessCharacter(char c)
{
  //Accepts users input and runs through string to find all equal characters
  bool answer = false;
  for(int i = 0; i < disguisedWordSize; i++)
  {
    if(secretWord.at(i) == c)
    {
      disguisedWord[i] = c;
      answer = true;
    }
  }
  if(answer == false)
  {
    missedMarkers[missesCount] = 'X';
    missesCount = missesCount + 1;
  }
  return(answer);
}
/*-------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------*/
bool Hangman::isGameOver()
{
  bool answer = true;
  //Checks if game is over
  if(missesCount == 7 || secretWord == disguisedWord)
  {
    answer = true;
  }
  else
  {
    answer = false;
  }
  return(answer);
}
/*-------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------*/
bool Hangman::isFound()
{
  bool answer = true;
  //Checks if user found the secret word
  for(int i = 0; i < disguisedWordSize; i++)
  {
    if(disguisedWord[i] == '?')
    {
      answer = false;
    }
  }
  return(answer);
}
/*-------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------*/
std::string Hangman::getDisguisedWord()
{
  std::string disguise(disguisedWord);
  return(disguisedWord);
}
/*-------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------*/
int Hangman::getGuessCount()
{
  guessCount = guessCount + 1;
  return(guessCount);
}
/*-------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------*/
int Hangman::getMissesCount()
{
  return(missesCount);
}
/*-------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------*/
std::string Hangman::getMissedMarker()
{
  std::string missed(missedMarkers);
  return(missed);
}
/*-------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------*/
