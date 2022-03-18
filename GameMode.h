#ifndef GAMEMODE_H
#define GAMEMODE_H

#include <iostream>
using namespace std;

class GameMode{
public:
  GameMode();
  ~GameMode();
private:
  int generationNum;
  int height;
  int width;
  array currgen;
  array nextgen;
  array generateArray(int h, int w, float p);
  void printArray();
  array simulate();

};

#endif
