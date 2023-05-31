#include<iostream>
#include"rectangle.h"
#include"shape.h"

using namespace std;

Rectangle::Rectangle(float length, float width){
   length=0;
   width=0;

}

Rectangle::Rectangle(){
   name="Rectangle";
   colour="blue";
}

float Rectangle::get_width()const{
   return width;
}

void Rectangle::set_width(float width){
   this->width=width;
}

float Rectangle::get_height()const{
   return height;
}

void Rectangle::set_height(float height){
   this->height=height;
}

int Rectangle::area(){
   return width*height;
}

