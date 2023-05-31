#ifndef DOG_H
#define DOF_H
#include<iostream>
#include<string>

using namespace std;

class Dog : public Pet{
private:
   string breed;
public:
   string get_breed();
   void set_breed(string);
   string getLifespan();

};
#endif
