#ifndef EVENT_H
#define EVENT_H
#include<iostream>

using namespace std;

class Event{
   protected:
      string name;
   public:
      virtual void precept()=0;
      virtual void encounter()=0;
      virtual string get_name()=0;
      virtual void set_name(string)=0;




};
#endif
