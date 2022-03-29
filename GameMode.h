#ifndef GAMEMODE_H
#define GAMEMODE_H

#include "FileProcessor.h"

class GameMode{

private:
  char gameMode; //"doughnut" "classic" or "mirror"
  int generationNum;
  int height; //rows
  int width; //cols
  char** boardArray;
  char** oldboardArray;
  FileProcessor f1;
public:
  GameMode();
  ~GameMode();
  void generateRandomArray(int h, int w, float p);
  void generateFileArray(string filename);
  void doBoardRound();
  void printArray();
  void clearOutFile(string outfilename);
  void printArrayToFile(string f);
  int getGenerationNum();
  void setGameMode(char g);
  bool isEmpty();
  bool isBalanced();
  int getNeighborCountClassic(int r, int c);
  int getNeighborCountMirror(int r, int c);
  int getNeighborCountDoughnut(int r, int c);
  void setHeight(int h);
  void setWidth(int w);
};

#endif
