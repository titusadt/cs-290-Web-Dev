#ifndef BATS_H
#define BATS_H
#include<iostream>
#include"event.h"

using namespace std;

class Bats : public Event{
   public:
      void precept();
      void encounter();
      string get_name();
      void set_name(string);

};
#endif
