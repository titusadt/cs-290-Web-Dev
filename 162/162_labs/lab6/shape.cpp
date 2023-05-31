#include<iostream>
#include"shape.h"

using namespace std;

Shape::Shape(){}
string Shape::get_name() const{
   return name;
}

void Shape::set_name(string name){
   this->name=name;
}

string Shape::get_colour() const{
   return colour;
}

void Shape::set_colour(string colour){
   this->colour=colour;
}

int Shape::area(){
   return 0;  
}


/*void print_area(Shape &sh){
   sh.shape_area();
}*/
