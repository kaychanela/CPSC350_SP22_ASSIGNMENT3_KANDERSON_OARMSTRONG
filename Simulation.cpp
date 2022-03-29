#include "Simulation.h"

Simulation::Simulation(){
  briefPause = true;
}
Simulation::~Simulation(){
}
void Simulation::setConfiguration(){
  int height;
  int width;
  float density;
  int response;
  cout << "Do you wish to wish to start with a random configuration (1), or provide a map file (2)." << endl;
  while(true){
    cin >> response;
    if(response == 1 || response == 2){
      break;
    }
    cin.clear();
    cout << "Invalid input: Please Enter 1 for random configuration or 2 to specify a flat-file configuration" << endl;
  }
  if(response == 1){
    cout << "Please enter the dimensions of the world (height width) each should be 1-50. (Ex. 5 5)" << endl;
    while(true){
      cin >> height;
      cin >> width;
      if(height > 0 && height < 50 && width > 0 && width < 50){
        break;
      }
      cin.clear();
      cout << "Invalid Input: At least one of your numbers was out of bounds, Please insert integer values for height and wicth. Ex (5 5)" << endl;
    }
    cout << "Please enter the density of the population (0-1). (Ex. 0.7)" << endl;
    while(true){
      cin >> density;
      if(density <= 1 && density > 0){
        break;
      }
      cin.clear();
      cout << "Invalid Input: Please insert proper density values. (0-1) Ex (0.7)" << endl;
    }
      g1.setWidth(width);
      g1.setHeight(height);
    g1.generateRandomArray(height,width,density);
  }
  else{
    cout << "Please enter the txt file name. (Do not include .txt)" << endl;
    cin >> infilename;
    g1.generateFileArray(infilename);
  }
}

void Simulation::getGameMode(){
  char gamemode;
  cout << "What kind of boundary mode to run in? (C for Classic, D for Doughnut, M for Mirror)" << endl;
  while(true){
    cin >> gamemode;
    if(tolower(gamemode) == 'c' || tolower(gamemode) == 'd' || tolower(gamemode) == 'm'){
      break;
    }
    cin.clear();
    cout << "Invalid Input: Please Enter c, d or m" << endl;
  }
  g1.setGameMode(gamemode);
}
void Simulation::setBriefPause(){
  char response;
  cout << "Do you wish to have a breif pause between generations?" << endl;
  cout << "Else generations will be outputed into a file." << endl;
  cout << "Type Y for yes or N for no." << endl;
  while(true){
    cin >> response;
    if(tolower(response) == 'n' || tolower(response) == 'y'){
      break;
    }
    cin.clear();
    cout << "Incorrect Input: Please Enter Y for yes or N for no." << endl;
  }
  if(tolower(response) == 'n'){
    briefPause = false;
    cout << "Enter the name of your desired output file" << endl;
    cin >> outfilename;
  }
  else{
    briefPause = true;
  }
}

void Simulation::startGame(){
  string response = "";
  setConfiguration();
  getGameMode();
  setBriefPause();
  if(briefPause){
    cout << "\n" << "0" << endl;
    g1.printArray();
    cout << "generation number " << to_string(g1.getGenerationNum()) << endl;
    g1.printArray();
  }
  else{
    g1.clearOutFile(outfilename);
    g1.printArrayToFile(outfilename);
    g1.printArrayToFile(outfilename);
  }
  while(!g1.isEmpty() && !g1.isBalanced()){//print first then second, if second is equal to first end
    if(briefPause){
      cout << "Press Enter to Continue..." << "\n" << endl;
      cin.clear();
      cin.ignore();
      g1.doBoardRound();
      if(!g1.isBalanced() && !g1.isEmpty()){
        cout << "generation number " << to_string(g1.getGenerationNum()) << endl;
        g1.printArray();
      }
    }
    else{
      g1.doBoardRound();
      if(!g1.isBalanced() && !g1.isEmpty()){
        g1.printArrayToFile(outfilename);
      }
    }
  }
  cout << "Simulation over, press Enter to exit." << endl;
  cin.clear();
  cin.ignore();
}
