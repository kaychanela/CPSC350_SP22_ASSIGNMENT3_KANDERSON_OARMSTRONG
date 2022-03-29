#include "GameMode.h"

GameMode::GameMode(){}

//method to update gamemode variable to desired char
void GameMode::setGameMode(char g) {
    gameMode = g;
}

//method that returns current generation number
int GameMode::getGenerationNum(){
    return generationNum;
}

//method to set height variable taking in int value
void GameMode::setHeight(int h){
    height = h;
}

//method to set width variable taking in int value
void GameMode::setWidth(int w){
    width = w;
}

//method to generate a random array based on user inputed integer values for height and width, plus float value representing population density
void GameMode::generateRandomArray(int h, int w, float p){
    //initialize empty board array and old board array
    boardArray = new char*[height];
    oldboardArray = new char*[height];
    for(int i = 0; i < height; i++){
        boardArray[i] = new char[width];
        oldboardArray[i] = new char[width];
    }
    //initialize generation number to 0, set height equal to user input
    generationNum = 0;
    height = h;
    width = w;

    //set threshold for comparing to isAlive here using p
    int threshold = p * 100; //turn to percentage so that we can easily use ints from rand()

    //populate boardArray based on density value
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

GameMode::~GameMode() {}

//method that takes current cell in boardArray and returns that cells neighbor count ~ classic version
int GameMode::getNeighborCountClassic(int row, int col){
  int count = 0;
  //CHECK ABOVE ~ current Cell
  if(row - 1 >= 0) { //if current cell has an above cell within bounds
    if(boardArray[row - 1][col] == 'X'){//then if there is an X at the above position, add to count
      ++count;
    }
  }
  //CHECK BELOW ~ current cell
  if(row + 1 < height) { //if current cell has a below cell within bounds
    if(boardArray[row + 1][col] == 'X'){//then if there is an X at the below position, add to count
      ++count;
    }
  }
  //CHECK LEFT ~ of current cell
  if(col - 1 >= 0) {//if the current cell has a cell to the left of it within bounds
    if(boardArray[row][col - 1 ] == 'X'){//then if there is an X at the left position, add to count
      ++count;
    }
  }
  //CHECK RIGHT ~ of current cell
  if(col + 1 < width) {//if the current cell has a cell to the right of it within bounds
    if(boardArray[row][col + 1] == 'X'){//then if there is an X at the right position, add to count
      ++count;
    }
  }
  //CHECK TOP LEFT ~ of current cell
  if(row - 1 >= 0 && col - 1 >= 0) {//if the current cell has a cell to the left top diagonally from it in bounds
    if(boardArray[row - 1][col - 1] == 'X'){//then if there is an X at the top left diagonal, add to count
      ++count;
    }
  }
  //CHECK TOP RIGHT ~ of current cell
  if(row - 1 >= 0 && col + 1 < width) {//if the current cell has a cell to the right top diagonally from it in bounds
    if(boardArray[row - 1][col + 1] == 'X'){//then if there is an X at the top right diagonal, add to count
      ++count;
    }
  }
  //CHECK BOTTOM LEFT ~ of current cell
  if(row + 1 < height && col - 1 >= 0) {//if the current cell has a cell to the left bottom diagonally from it in bounds
    if(boardArray[row + 1][col - 1] == 'X'){//then if there is an X at the bottom left diagonal, add to count
      ++count;
    }
  }
  //CHECK TOP RIGHT ~ of current cell
  if(row + 1 < height && col + 1 < width) {//if the current cell has a cell to the right bottom diagonally form it in bounds
    if(boardArray[row + 1][col + 1] == 'X'){//then if there is an X at the bottom right diagonal, add to count
      ++count;
    }
  }
  return count;
}

//method that takes current cell in boardArray and returns that cells neighbor count ~ doughnut version
int GameMode::getNeighborCountDoughnut(int row, int col){
  int count = 0;
  //CHECK ABOVE ~ current cell
  if(row - 1 >= 0) {//if there exist a cell above current cell within bounds
    if(boardArray[row - 1][col] == 'X'){//if cell is occupied, add to count
      count++;
    }
  }
  //else check WRAP AROUND BOTTOM
  else{//above is out of bounds
    if(boardArray[height - 1][col] == 'X'){//check wrap around bottom in same column, if occupied, add to count
      count++;
    }
  }
  //CHECK BELOW ~ current cell
  if(row + 1 < height) {
    if(boardArray[row + 1][col] == 'X'){//if there exist a cell below current cell within bounds
      count++;//if cell is occupied, add to count
    }
  }
  //else check WRAP AROUND TOP
  else{
    if(boardArray[0][col] == 'X'){//check wrap around top row in same column, if occupied, add to count
      count++;
    }
  }
  //CHECK LEFT ~ of current cell
  if(col - 1 >= 0) {//if there exist a cell to the left of current cell within bounds
    if(boardArray[row][col - 1 ] == 'X'){//if cell is occupied, add to count
      count++;
    }
  }
  //else check WRAP AROUND TO THE RIGHT SIDE
  else{
    if(boardArray[row][width - 1] == 'X'){//check wrap around right, if occupied, add to count
      count++;
    }
  }
  //CHECK RIGHT ~ of current cell
  if(col + 1 < width) {//if there exist a cell to the right of current cell within bounds
    if(boardArray[row][col + 1] == 'X'){//if cell is occupied, add to count
      count++;
    }
  }
  //else check WRAP AROUND TO THE LEFT
  else{
    if(boardArray[row][0] == 'X'){//check wrap around right, if occupied, add to count
      count++;
    }
  }
  //CHECK ABOVE LEFT ~ of current cell
  if(row - 1 >= 0 && col - 1 >= 0) {//if there exist a cell to the top left of current cell within bounds
    if(boardArray[row - 1][col - 1] == 'X'){//if cell is occupied, add to count
      count++;
    }
  }
  //ChECK ONLY FIRST COLUMN, IGNORE TOP ROW
  else if(row > 0){
    if(boardArray[row - 1][width - 1] == 'X'){//if there exist an occupied cell on wrap around (last column, row above), add to count
      count++;
    }
  }
  //CHECK ONLY TOP ROW, IGNORE FIRST COLUMN
  else if(col > 0){
    if(boardArray[height - 1][col - 1] == 'X'){//if there exist an occupied cell on wrap around (last row, left one column), add to count
      count++;
    }
  }
  //CHECK TOP LEFT CORNER
  else{
    if(boardArray[height - 1][width - 1] == 'X'){//if there exist an occupied cell on wrap (bottom left corner of grid), add to count
      count++;
    }
  }
  //CHECK ABOVE RIGHT ~ of current cell
  if(row - 1 >= 0 && col + 1 < width) {//if there exist a cell to the top right of current cell within bounds
    if(boardArray[row - 1][col + 1] == 'X'){//if cell is occupied, add to count
      count++;
    }
  }
  //CHECK ONLY TOP ROW, IGNORE LAST COLUMN
  else if(col < (width - 1)){
    if(boardArray[height - 1][col + 1] == 'X'){//if there exist an occupied cell on wrap (last row, right one column), add to count
      count++;
    }
  }
  //CHECK ONLY LAST COLUMN, IGNORE FIRST ROW
  else if(row > 0){
    if(boardArray[row - 1][0] == 'X'){//if there exist an ocupied cell on wrap (first column, ), add to count
      count++;
    }
  }
  //CHECK TOP RIGHT CORNER
  else{
    if(boardArray[height - 1][0] == 'X'){//if there exist an occupied cell on bottom left corner of board, add to count
      count++;
    }
  }
  //CHECK BELOW LEFT ~ of current cell
  if(row + 1 < height && col - 1 >= 0) {//if there exist a cell to the bottom left of current cell within bounds
    if(boardArray[row + 1][col - 1] == 'X'){//if cell is occupied, add to count
      count++;
    }
  }
  //CHECK ONLY LAST ROW, IGNORE FIRST COLUMN
  else if(col > 0) {
    if(boardArray[0][col - 1] == 'X'){//if there exist an occupied cell on wrap (first row, to the left one column), add to count
      count++;
    }
  }
  //CHECK ONLY FIRST COLUMN, IGNORE LAST ROW
  else if(row < (height - 1)){
    if(boardArray[row + 1][width - 1] == 'X'){//if there exist an occupied cell on wrap (down one row, last column), add to count
      count++;
    }
  }
  //CHECK BOTTOM LEFT CORNER
  else{
    if(boardArray[0][width - 1] == 'X'){//if there exist an occupied cell on top right corner of grid, add to count
      count++;
    }
  }
  //CHECK BELOW RIGHT ~ of current cell
  if(row + 1 < height && col + 1 < width) {//if there exist a cell to the bottom right of current cell within bounds
    if(boardArray[row + 1][col + 1] == 'X'){//if cell is occupied, add to count
      count++;
    }
  }
  //CHECK ONLY LAST ROW, IGNORE LAST COLUMN
  else if(col < (width - 1)){
    if(boardArray[0][col + 1] == 'X'){//if there exist an occupied cell on wrap (first row, over one column), add to count
      count++;
    }
  }
  //CHECK ONLY LAST COLUMN, IGNORE LAST ROW
  else if(row < (height - 1)){
    if(boardArray[row + 1][0] == 'X'){//if there exist an occupied cell on wrap (above one row, first column), add to count
      count++;
    }
  }
  //CHECK BOTTOM RIGHT CORNER
  else{
    if(boardArray[0][0] == 'X'){//if there exist an occupied cell on top right corner, add to count
      count++;
    }
  }
  return count;
}

//method that takes current cell in boardArray and returns that cells neighbor count ~ mirror version
int GameMode::getNeighborCountMirror(int row, int col){
  int count = 0;
  //CHECK ABOVE ~ current cell
  if(row - 1 >= 0){ //if current cell has a cell above it within bounds
    if(boardArray[row - 1][col] == 'X'){//then if the cell is occupied, add to count
      ++count;
    }
  }
  //else CHECK ABOVE REFLECTION
  else{
    if(boardArray[row][col] == 'X'){//Above is out of bounds then check if current cell is occupied, add to count
        ++count;
    }
  }
  //CHECK BELOW ~ current cell
  if(row + 1 < height){ //if current cell has a cell below it within bounds
    if(boardArray[row + 1][col] == 'X'){//then if cell is occupied, add to count
      ++count;
    }
  }
  //else CHECK BELOW REFLECTION
  else{
    if(boardArray[row][col] == 'X'){//Below is out of bounds then check if current cell is occupied, add to count
      ++count;
    }
  }
  //CHECK LEFT ~ of current cell
  if(col - 1 >= 0){//if a current cell has a cell to the left of it within bounds
    if(boardArray[row][col - 1] == 'X'){//then check if cell is occuped, add to count
      ++count;
    }
  }
  //else CHECK LEFT REFLECTION
  else{
    if(boardArray[row][col] == 'X'){//Left is out of bounds, then check if current cell is occupied, add to count
      ++count;
      }
    }
  //CHECK RIGHT ~ of current cell
  if(col + 1 < width){//if a current cell has a cell to the right if it eithin bounds
    if(boardArray[row][col + 1] == 'X'){//then check if cell is occupied, add to count
      ++count;
      }
    }
  //else CHECK RIGHT REFLECTION
  else{
    if(boardArray[row][col] == 'X'){//Right is out of bounds, then check if current cell is occupied, add to count
      ++count;
    }
  }
  //CHECK ABOVE LEFT ~ of current cell
  if(row - 1 >= 0 && col - 1 >= 0){//if a current cell has a cell to the top left of it within bounds
    if(boardArray[row - 1][col - 1] == 'X'){//then check if cell is occupied, add to count
      ++count;
    }
  }
  //else CHECK ABOVE LEFT REFLECTION
  else{
    if(row == 0 && col != 0 && boardArray[row][col - 1] == 'X'){//if current cell is located on top boarder, not left corner and left neighbor is occupied, add to count
      ++count;
    }
    if(col == 0 && row != 0 && boardArray[row - 1][col] == 'X'){//if current cell is located on left boarder, not top corner and is occupied, add to count
      ++count;
    }
    if(col == 0 && row == 0 && boardArray[row][col] == 'X'){//if current cell is located on left corner, and is occupied, add to count
      ++count;
    }
  }
  //CHECK ABOVE RIGHT ~ of current cell
  if(row - 1 >= 0 && col + 1 < width) {//if current cell has a cell to the top right of it within bounds
    if(boardArray[row - 1][col + 1] == 'X'){//then check if cell is occupied, add to count
      ++count;
    }
  }
  //else CHECK ABOVE RIGHT REFLECTION
  else{
    if(col != (width - 1) && row == 0 && boardArray[row][col + 1] == 'X'){//if current cell is located on top boarder, not right corner, and right neightbor is occupied, add to count
      ++count;
    }
    if(col == (width - 1) && row != 0 && boardArray[row - 1][col] == 'X'){//if current cell is located on last column, not top corner, and above neightboor is occupied, add to count
      ++count;
    }
    if(col == (width - 1) && row == 0 && boardArray[row][col] == 'X'){//if current cell is located on last column, not top corner, and above neightboor is occupied, add to count
      ++count;
    }
  }
  //CHECK BOTTOM LEFT ~ of current cell
  if(row + 1 < height && col - 1 >= 0){//if current cell has a cell to the bottom left of it within bounds
    if(boardArray[row + 1][col - 1] == 'X'){//then check if cell is occupied, add to count
      ++count;
    }
  }
  //else CHECK BOTTOM LEFT REFLECTION
  else{
    if(row == (height - 1) && col != 0 && boardArray[row][col - 1] == 'X'){//if current cell is located on bottom boarder, not left corner, and left neightbor is occupied, add to count
      ++count;
    }
    if(col == 0 && row != (height - 1) && boardArray[row + 1][col] == 'X'){//if current cell is located on left boarder, not bottom corner, and bottom neighbor is occupied, add to count
      ++count;
    }
    if(col == 0 && row == (height - 1) && boardArray[row][col] == 'X'){//if current cell is located on left boarder, not bottom corner, and bottom neighbor is occupied, add to count
      ++count;
    }
  }
  //CHECK BOTTOM RIGHT ~ of current cell
  if(row + 1 < height && col + 1 < width){//if current cell has a cell to the bottom right of it within bounds
    if(boardArray[row + 1][col + 1] == 'X'){//then check if cell is occupied, add to count
      ++count;
    }
  }
  //else CHECK BOTTOM RIGHT REFLECTION
  else{
    if(col != (width - 1) && row == (height - 1) && boardArray[row][col + 1] == 'X'){//if current cell is located on last row, not right corner, and right neighbor is occupied, add to count
      ++count;
    }
    if(col == (width - 1) && row != (height - 1) && boardArray[row + 1][col] == 'X'){//if current cell is located on last column, not bottom corner, and bottom neighbor is occupied, add to count
      ++count;
    }
    if(col == (width - 1) && row == (height - 1) && boardArray[row][col] == 'X'){//if current cell is located on last column, not bottom corner, and bottom neighbor is occupied, add to count
      ++count;
    }
  }
  return count;
  cout << count << "\n";
}

//method that clears out the output file of old data
void GameMode::clearOutFile(string outfilename){
  f1.clearFile(outfilename);
}

//method that iterates through each cell in the boardArray and calls on specific neighbor counter based on user input
//populates new temp array based on returned neighbor count and replaces boardArray with temp array
void GameMode::doBoardRound(){
  //initialize temp arra for changes
  char** nextBoard = new char*[height];
  for(int i = 0; i < height; i++){
    nextBoard[i] = new char[width];
  }
  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      nextBoard[i][j] = boardArray[i][j];
      oldboardArray[i][j] = boardArray[i][j];
    }
  }
  //iterate through boardArray and calculate changes based on game mode
  for(int row = 0; row < height; row++){
    for(int col = 0; col < width; col++){
      int neighbors;
      if(gameMode == 'c'){
        neighbors = getNeighborCountClassic(row, col);
      }
      else if(gameMode == 'd'){
        neighbors = getNeighborCountDoughnut(row, col);
      }
      else if(gameMode == 'm'){
        neighbors = getNeighborCountMirror(row, col);
      }
      if(neighbors <= 1){
        nextBoard[row][col] = '-';
      }
      else if(neighbors == 2){
        nextBoard[row][col] = oldboardArray[row][col];
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
//method to print out boardArray to terminal, updates generation count
void GameMode::printArray(){
    string ret;
    ret = "";
    for(int i = 0; i < height; ++i ){
        for(int j = 0; j < width; ++j){
            ret += boardArray[i][j];
        }
        ret += "\n";
    }
    cout << ret << endl;
    ++generationNum;
}

//method to print our current boardArray to user file, updates generation count
void GameMode::printArrayToFile(string filename){
    f1.printToFile(boardArray,height,width,generationNum,filename);
    ++generationNum;
}

//method that generates an array boardArray based on user given file
void GameMode::generateFileArray(string filename){
  //initiallze boardArray and oldboardArray
    boardArray = new char*[height];
    oldboardArray = new char*[height];
    for(int i = 0; i < height; i++){
        boardArray[i] = new char[width];
        oldboardArray[i] = new char[width];
    }
    generationNum = 0;

    //process file into a string and break string up into an array
    string arrString = f1.processFile(filename);
    height = arrString[0] - '0';
    width = arrString[1] - '0';
    int s = 2;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            boardArray[i][j] = arrString[s];
            ++s;
        }
    }
}

//function that checks if current generation is emptied of X's
bool GameMode::isEmpty(){
    for(int i = 0; i < height; ++i ){
        for(int j = 0; j < width; ++j){
            if(boardArray[i][j] == 'X'){
                return false;
                break;
            }
        }
    }
    return true;
}

//function that compares previos boardArray with current boardArray to check is simulation is balanced
bool GameMode::isBalanced(){
  for(int i = 0; i < height; ++i ){
      for(int j = 0; j < width; ++j){
          if(oldboardArray[i][j] != boardArray[i][j]){
              return false;
              break;
          }
      }
  }
  return true;
}
