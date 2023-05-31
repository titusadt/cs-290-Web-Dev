#ifndef GOLD_H
#define GOLD_H
#include<iostream>
#include"event.h"

using namespace std;

class Gold : public Event{
   public:
      void precept();
      void encounter();
      string get_name();
      void set_name(string);

};
#endif
