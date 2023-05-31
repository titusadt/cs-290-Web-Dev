#include<iostream>
#include"shape.h"
#include"circle.h"

using namespace std;


float Circle::get_radius()const{
   return radius;
}

void Circle::set_radius(float radius){
   this->radius=radius;
}

Circle::Circle(){
   name="Circle";
   colour="red";
}

int Circle::area(){
   return 3.14159265*radius*radius;

}
