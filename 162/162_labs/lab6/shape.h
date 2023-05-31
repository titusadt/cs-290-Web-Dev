#ifndef SHAPE_H
#define SHAPE_H
#include<iostream>
#include<string>

using namespace std;

class Shape{
   protected:
      string name;
      string colour;
   public:
      Shape();
      string get_name() const;
      void set_name(string);
      string get_colour() const;
      void set_colour(string);
      virtual int area()=0;
      bool &operator >(const Shape &s2);
      bool &operator <(const Shape &s2);
      //virtual void shape_area()=0;
      void print_area(Shape &);
};
#endif
