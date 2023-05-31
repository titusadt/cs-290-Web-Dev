#ifndef ROOM_H
#define ROOM_H
#include<iostream>
#include "event.h"
using namespace std;

class Room{
   private:
     Event* event;
   public:
     Room();
     string get_name();
     Event* get_event();
     void set_event(Event*);
};
#endif
