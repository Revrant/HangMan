#include "GameDriver.h"
#include <iostream>
#include <string>
//Creates Object
GameDriver::GameDriver()
{
  myHangman = nullptr;
}

void GameDriver::run(std::string word)
{
  char exit = 'y';
  char c = '\0';
  int guess = 0; //Keeps track of guesses

  myHangman = new Hangman(word);
  do
  {
    std::cout << std::endl;
    std::cout << "Welcome to the Hangman Game!" << '\n';
    std::cout << "----------------------------" << '\n';
/*-------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------*/
    do
    {
      std::cout << std::endl;
      //Function calls
      std::cout << "Guess this: " << myHangman->getDisguisedWord() << '\n';
      std::cout << "Guesses so far: " << myHangman->getGuessCount() << '\n';
      std::cout << "Misses: " << myHangman->getMissedMarker() << '\n';
      std::cout << "Enter your guess character: ";
      std::cin >> c;
      //Checks if user input is in the secret word
      if(myHangman->guessCharacter(c) == true)
      {
        std::cout << c << " is in the secret word!" << '\n';
      }
      else
      {
        std::cout << c << " is not in the secret word. Death draws closer." << '\n';
        myHangman->getMissesCount();
      }
      guess = guess + 1; //Loops guesses
    }while(myHangman->isGameOver() == false);//Loops till game is finished
/*-------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------*/
    std::cout << std::endl;
    std::cout <<"Game Over!" << '\n';

    if(myHangman->isFound() == true)
    {
      std::cout << "Congratulations! You guessed the secret word: " << myHangman->getDisguisedWord() << " in " << guess << " guesses!" << '\n';
    }
    else
    {
      std::cout << "You died. Next time, guess as if your life depended on it." << '\n';
    }
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> exit;
/*-------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------*/
    if(exit == 'y')
    {
      std::cout << "Input a new secret word: ";
      std::cin.ignore(1000, '\n');
      std::getline(std::cin, word); //Allows user to input more than one word and resets the secret word
      myHangman = new Hangman(word);

      for(int i = 0; i < 99; i++) //Prints 100 new lines
      {
        std::cout<<std::endl;
      }
    }

  }while(exit != 'n');
  std::cout << std::endl;
  std::cout << "Thanks for playing Hang Man!" << '\n';
}
