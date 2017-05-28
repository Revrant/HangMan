/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp Hangman.h Hangman.cpp GameDriver.h GameDriver.cpp
 * Author: Tristen Schwarzenberger
 * Assignment:   EECS-168 Homework 4
 * Description:  This program has user input a word and plays Hangman
 * Date: 11/18/2016
 *
 ---------------------------------------------------------------------------- */
#include <iostream>
#include "GameDriver.h"
#include <string>

int main(int argc, char** argv)
{
  std::string start;
  if(argc < 2) //Checks if user only starts program without inputing a word
  {
    std::cout << "You need a parameter!\n";
    return(1);
  }
  else
  {
    for(int i = 1; i < argc; i++)
    {
      start += argv[i];
      if(i != argc - 1)
      {
        start += ' ';
      }
    }
  }
  //Declares object and runs in GameDriver.cpp
  GameDriver game;
  game.run(start);

  return(0);
}
