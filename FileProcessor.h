#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class FileProcessor{
private:
public:
  FileProcessor();
  ~FileProcessor();
  string processFile(string filename);
  void printToFile(char** arr,int height, int length, int gennum, string filename);
  void clearFile(string filename);
};

#endif
