#ifndef OTTER_H
#define OTTER_H
#include<iostream>
#include<string>
#include"animal.h"

using namespace std;

class Otter: public Animal{
  public:
   Otter();  
   Otter(int);
};
#endif
