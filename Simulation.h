#ifndef SIMULATE_H
#define SIMULATE_H

#include <iostream>
using namespace std;

template <class T> class Simulation{
private:
  bool briefpause;
  T gameMode;
  void setConfiguration();
  void startGame();
  void setGameMode();
public:
  Simulation();
  ~Simulation();

};
