#include<iostream>
#include<fstream>
#include<string>
#include"pizza.h"
#include"menu.h"
#include"restaurant.h"

using namespace std;

int main(){
   int b;
   string a;
   string* i;
   Menu m;
   m.read_pizza();
   m.print();
   m.search_pizza_by_cost(b, a).print(); 
   m.search_pizza_by_ingridients_to_include(i , b);









return 0;
}
