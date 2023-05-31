#ifndef RECTANGLE_H
#define RECTANGLE_H
#include<iostream>
#include"shape.h"

using namespace std;

class Rectangle : public Shape{
   private:
      float width;
      float height;
   public:
      Rectangle();
      Rectangle(float, float);
      float get_width()const;
      void set_width(float);
      float get_height()const;
      void set_height(float);
      int area();
      void shape_area();

};
#endif
