#ifndef GAMEMODE_H
#define GAMEMODE_H

#include <iostream>
using namespace std;

class GameMode{
public:
  GameMode();
  GameMode(array curr);
  ~GameMode();
private:
  int height;
  int width;
  bool briefpause;
  array currgen;
  array nextgen;
  array generateArray(int h, int w, float p);
  array simulate();
  void playGame();
};

#endif
