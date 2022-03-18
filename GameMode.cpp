#include "GameMode.h"

GameMode::GameMode() {
  boardArray = new char*[height];
    for(int i = 0; i < height; i++){
        boardArray[i] = new char[width];
    }
}

void GameMode::generateRandomArray(int h, int w, float p){
  height = h;
  width = w;

  //set threshold for comparing to isAlive here using p

  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      int isAlive = rand(); //do math TODO
      if(/*compare isAlive to threshold if true here*/){
        boardArray[i][j] = 'X';
      }
      else{
        boardArray[i][j] = '-';
      }
    }
  }
}

GameMode::~GameMode() {

}

int GameMode::getNeighborCountClassic(int row, int col){

  int count;

  //if in boundary of array for row - 1, col unchanged
    //if array at new coords == 'X'
      //then neighbor count++
  //if in boundary of array for row + 1, col unchanged
    //if array at new coords == 'X'
        //then neighbor count++
  //if in boundary of array for row unchanged, col - 1
    //if array at new coords == 'X'
        //then neighbor count++
  //if in boundary of array for row unchanged, col + 1
    //if array at new coords == 'X'
        //then neighbor count++

  //if in boundary of array for row -1, col -1
    //if array at new coords == 'X'
        //then neighbor count++
  //if in boundary of array for row -1, col +1
    //if array at new coords == 'X'
        //then neighbor count++
  //if in boundary of array for row + 1, col -1
    //if array at new coords == 'X'
        //then neighbor count++
  //if in boundary of array for row + 1, col + 1
    //if array at new coords == 'X'
        //then neighbor count++


  return count;
}

int GameMode::getNeighborCountDoughnut(int row, int col){

  int count;

  //if in boundary of array for row - 1, col unchanged
    //if array at new coords == 'X'
      //then neighbor count++
  //else
    //array at height - 1, col unchanged == 'X'
      //then neighbor count ++
  //-------------------------------------------------------------------
  //if in boundary of array for row + 1, col unchanged
    //if array at new coords == 'X'
        //then neighbor count++
  //else
    //array at 0, col unchanged == 'X'
      //then neighbor count ++
  //-------------------------------------------------------------------
  //if in boundary of array for row unchanged, col - 1
    //if array at new coords == 'X'
        //then neighbor count++
  //else
    //array at row, width - 1 == 'X'
      //then neighbor count ++
  //-------------------------------------------------------------------
  //if in boundary of array for row unchanged, col + 1
    //if array at new coords == 'X'
        //then neighbor count++
  //else
    //array at row, 0 == 'X'
      //then neighbor count ++
  //-------------------------------------------------------------------

  ////////////////////// DIAGONALS ////////////////////////////////
  //if in boundary of array for row -1, col -1
    //if array at new coords == 'X'
        //then neighbor count++
  //else
    //array at height, width == 'X'
      //then neighbor count ++
  //-------------------------------------------------------------------
  //if in boundary of array for row -1, col +1
    //if array at new coords == 'X'
        //then neighbor count++
  //else
    //array at height, 0 == 'X'
      //then neighbor count ++
  //-------------------------------------------------------------------
  //if in boundary of array for row + 1, col -1
    //if array at new coords == 'X'
        //then neighbor count++
  //else
    //array at 0, width == 'X'
      //then neighbor count ++
  //-------------------------------------------------------------------
  //if in boundary of array for row + 1, col + 1
    //if array at new coords == 'X'
        //then neighbor count++
  //else
    //array at 0, 0 == 'X'
      //then neighbor count ++
  //-------------------------------------------------------------------


  return count;
}

int GameMode::getNeighborCountMirror(int row, int col){

  int count;

  //if in boundary of array for row - 1, col unchanged
    //if array at new coords == 'X'
      //then neighbor count++
  //else
    //array at row, col unchanged == 'X'
      //then neighbor count ++
  //-------------------------------------------------------------------
  //if in boundary of array for row + 1, col unchanged
    //if array at new coords == 'X'
        //then neighbor count++
  //else
    //array at row, col unchanged == 'X'
      //then neighbor count ++
  //-------------------------------------------------------------------
  //if in boundary of array for row unchanged, col - 1
    //if array at new coords == 'X'
        //then neighbor count++
  //else
    //array at row, col == 'X'
      //then neighbor count ++
  //-------------------------------------------------------------------
  //if in boundary of array for row unchanged, col + 1
    //if array at new coords == 'X'
        //then neighbor count++
  //else
    //array at row, col == 'X'
      //then neighbor count ++
  //-------------------------------------------------------------------

  ////////////////////// DIAGONALS ////////////////////////////////
  //if in boundary of array for row -1, col -1
    //if array at new coords == 'X'
        //then neighbor count++
  //else
    //array at row,col == 'X'
      //then neighbor count ++
  //-------------------------------------------------------------------
  //if in boundary of array for row -1, col +1
    //if array at new coords == 'X'
        //then neighbor count++
  //else
    //array at row,col == 'X'
      //then neighbor count ++
  //-------------------------------------------------------------------
  //if in boundary of array for row + 1, col -1
    //if array at new coords == 'X'
        //then neighbor count++
  //else
    //array at row,col == 'X'
      //then neighbor count ++
  //-------------------------------------------------------------------
  //if in boundary of array for row + 1, col + 1
    //if array at new coords == 'X'
        //then neighbor count++
  //else
    //array at row,col == 'X'
      //then neighbor count ++
  //-------------------------------------------------------------------


  return count;
}
