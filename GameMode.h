#ifndef GAMEMODE_H
#define GAMEMODE_H

#include <iostream>
using namespace std;

class GameMode{

private:
  int generationNum;
  int height; //rows
  int width; //cols
  string boundaryType;
  char** boardArray;
  void generateRandomArray(int h, int w, float p);
  void generateFileArray();
  void simulate();
public:
  GameMode();
  int getNeighborCountClassic(int row, int col);
  int getNeighborCountDoughnut(int row, int col);
  int getNeighborCountMirror(int row, int col);
  void printArray();
  ~GameMode();
};

#endif
