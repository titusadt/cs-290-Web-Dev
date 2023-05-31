#ifndef PIT_H
#define PIT_H
#include<iostream>
#include"event.h"

using namespace std;

class Pit : public Event{
   public:
      void precept();
      void encounter();
      string get_name();
      void set_name(string);

};
#endif
