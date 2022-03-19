#include "GameMode.h"

GameMode::GameMode() {
  boardArray = new char*[height];
    for(int i = 0; i < height; i++){
        boardArray[i] = new char[width];
    }
}

//p assumed to be between 0 and 1, for a percentage displayed as decimal
void GameMode::generateRandomArray(int h, int w, float p)
{
  height = h;
  width = w;

  //set threshold for comparing to isAlive here using p
  int threshold = p * 100; //turn to percentage so that we can easily use ints from rand()

  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      int isAlive = rand() % 100 + 1; //rand() % 100 = 0-99, add 1 to get desired 1-100 range
      if(isAlive <= threshold){ //under threshold means alive
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

  int count = 0;

  //if in boundary of array for row - 1, col unchanged
  if(row - 1 >= 0) {
    //if array at new coords == 'X'
    if(boardArray[row - 1][col] == 'X'){
      //then neighbor count++
      count++;
    }
  }
  //else
  else{ //over border
    //array at height - 1, col unchanged == 'X'
    if(boardArray[height - 1][col] == 'X'){
      //then neighbor count ++
      count++;
    }

  }
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

void GameMode::doBoardRound(){

  char** nextBoard = new char*[height];
  for(int i = 0; i < height; i++){
    boardArray[i] = new char[width];
  }

  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      nextBoard[i][j] = boardArray[i][j];
    }
  }

  for(int row = 0; row < height; row++){
    for(int col = 0; col < width; col++){
      int neighbors;
      if(gameMode.compare("classic") == 0){
        neighbors = getNeighborCountClassic(row, col);
      }
      else if(gameMode.compare("doughnut") == 0){
        neighbors = getNeighborCountDoughnut(row, col);
      }
      else if(gameMode.compare("mirror") == 0){
        neighbors = getNeighborCountMirror(row, col);
      }

      if(neighbors <= 1){
        nextBoard[row][col] = '-';
      }
      else if(neighbors == 3){
        nextBoard[row][col] = 'X';
      }
      else if(neighbors >= 4){
        nextBoard[row][col] = '-';
      }
    }
  }

  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      boardArray[i][j] = nextBoard[i][j];
    }
  }

}
