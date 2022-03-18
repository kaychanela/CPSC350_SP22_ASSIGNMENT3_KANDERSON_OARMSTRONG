#include <Simulation>

Simulation::Simulation(){
  briefpause = true;
  GameMode g1;
}
~Simulation::Simulation(){
}
void Simulation::setConfiguration(){
  int height;
  int width;
  float density;
  cout << "Do you wish to wish to start with a random configuration (1), or provide a map file (2)." << endl;
  cout << "Enter 1 or 2" << endl;
  while(false){
    cin >> response >> endl;
    if(response == "1" || "2"){
      break;
    }
    else{
      cout << "Invalid input: Please Enter 1 for random configuration or 2 to specify a flat-file configuration" << endl;
    }
  }
  if(response == "1"){
    cout << "Please enter the dimensions of the world (height width). (Ex. 5 5)" << endl;
    cin >> height >> endl;
    cin >> width >> endl;
    cout << "Please enter the density of the population. (Ex. 6.7)" << endl;
    cin >> density >> endl;
    g1.generateRandomArray(height,width,density);
  }
  else{
    cout << "Please enter the file name." << endl;
    cin >> filename >> endl;
    f1.readFile(filename);
  }
}

void Simulation::setGameMode(){
  cout << "What kind of boundary mode to run in? (Classic, Doughnut, Mirror)" << endl;
  while(false){
    cin >> gamemode >> endl;
    if(tolower(gamemode) == "classic" || "doughnut" || "mirror"){
      break;
    }
    else{
      cout << "Invalid Input: Please Enter Classic, Doughnnut or Mirror" << endl;
    }
  }
  cout <<
}

void Simulation::startGame(){
  string response = NULL;
  FileReader f1;
  string filename;

}
