#include "FileProcessor.h"

FileProcessor::FileProcessor(){}
FileProcessor::~FileProcessor(){}

//function reads from a user given file and returns content via string
string FileProcessor::processFile(string input){
  ifstream importfile;
  string ret;
  importfile.open(input + ".txt");
  if(importfile.is_open()){
    while(!importfile.eof()){
      string currline;
      importfile >> currline;
      ret += currline;
    }
  }

  importfile.close();
  return ret;
}

//function that clears out file of previous data
void FileProcessor::clearFile(string filename){
  ofstream outputfile;
  outputfile.open(filename + ".txt");
  if(outputfile.is_open()){
    outputfile << "";
  }
  outputfile.close();
}

//function that writes boardArray into a file alonf with current generation stats
void FileProcessor::printToFile(char** arr,int height, int width, int gennum, string filename){
  ofstream outputfile;
  int h = height;
  int w = width;
  outputfile.open(filename + ".txt", ios_base::app);
  if(outputfile.is_open()){
    outputfile << "generation number " << gennum << endl;
    for(int i = 0; i < h; ++ i){
      for(int j = 0; j < w; ++j){
        outputfile << arr[i][j];
      }
      outputfile << "\n";
    }
  }
  outputfile.close();
}
