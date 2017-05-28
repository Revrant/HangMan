#ifndef GAMEDRIVER_H
#define GAMEDRIVER_H
#include <iostream>
#include "Hangman.h"
#include <string>

class GameDriver
{
public:
  Hangman* myHangman;//Object
  GameDriver();//Constructor
  void run(std::string word);//Run Function
};
#endif
