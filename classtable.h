#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include <cmath>
#include <thread>
#include <unistd.h>
using namespace std;


const int max_numb=10;


class table{
public:
  string status = "available";
  clock_t starttime;
  char type;
  int numb;
  void occupy(){
    status="occupied";
    starttime=clock();
}
  void print(){cout << setw(3)<< type << numb <<"    "<< status << endl;}
};
