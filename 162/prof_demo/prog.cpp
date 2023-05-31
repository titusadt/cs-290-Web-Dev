#include"pet.h"
#include"dog.h"
#include<iostream>

using namespace std;

int main(){
   Dog *dogs;
   Pet p;
   string ans, type, new_life;
   int choice=0, num_dogs=0;
   cout << "Enter the name of the dog: ";
   cin  >> ans;
   p.set_name(ans);
   cout << "Enter the weight of the dog: ";
   cin >>choice;
   p.set_weight(choice);
   string lifespan = p.getLifespan();

   cout << lifespan << endl;
	
   cout << "Enter the number of dogs: ";
   cin >> num_dogs;

   dogs = new Dog[num_dogs]; // dynamic array for dogs

   for(int i =0; i< num_dogs; i++){
      cout <<"Enter the breed of the dog: ";
      cin >> type;
      dogs[i].set_breed(type);
   }
   for(int j = 0; j<num_dogs; j++){
   
      new_life = dogs[j].getLifespan();
   cout << new_life << endl;
   }
return 0;
}
