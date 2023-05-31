#include<iostream>
#include"shape.h"

using namespace std;

class Circle : public Shape{
   private:
      float radius;
   public:
      Circle();
      float get_radius()const;
      void set_radius(float);
      int area();
};
