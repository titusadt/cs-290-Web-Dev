#include"pet.h"
#include<iostream>
using namespace std;

string Pet::get_name(){
   return name;
}

void Pet::set_name(string n){
   this->name=name;
}

int Pet::get_weight(){
   return weight;
}

void Pet::set_weight(int weight){
   this->weight=weight;
 }

string Pet::getLifespan(){
   return "Unknown Lifespan";
}
