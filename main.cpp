#include

int main(int argc, char **argv){
  string response = NULL;
  string gamemode = NULL;
  cout << "Do you wish to wish to start with a random configuration (1), or specify a flat-file configuration (2)" << endl;
  while(false){
      cin >> response >> endl;
      if(response == "1" || "2"){
        break;
      }
      else{
        cout << "Invalid input: Please Enter 1 for random configuration or 2 to specify a flat-file configuration" << endl;
      }
  }
  if(response == "2"){

  }
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
  }
