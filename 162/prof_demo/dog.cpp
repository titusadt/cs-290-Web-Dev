#include"pet.h"
#include"dog.h"
#include<iostream>
#include<string>

using namespace std;

string Dog::get_breed(){
   return breed;
}

void Dog::set_breed(string breed ){
   this->breed=breed;
}

string Dog::getLifespan(){
   if(weight > 100){
      return "Approximately 7 years";
   }
   else if(weight <100){
      return "Approximately 13 years";
   }


}
