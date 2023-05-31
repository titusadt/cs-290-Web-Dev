#ifndef PET_H
#define PET_H
#include<iostream>
#include <string>

using namespace std;

class Pet{
   protected:
      string name;
      int weight;
   public:
      string get_name();
      void set_name(string);
      int get_weight();
      void set_weight(int);
      virtual string getLifespan();
 
};

#endif
