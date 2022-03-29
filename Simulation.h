#ifndef SIMULATION_H
#define SIMULATION_H

#include "GameMode.h"

class Simulation{
private:
  bool briefPause;
  string infilename;
  string outfilename;
  GameMode g1;
public:
  void setConfiguration();
  void setBriefPause();
  void startGame();
  void getGameMode();
  Simulation();
  ~Simulation();

};
#endif
