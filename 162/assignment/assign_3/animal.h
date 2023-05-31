#ifndef ANIMAL_H
#define ANIMAL_H
#include<iostream>
#include<string>

using namespace std;

class Animal{
   protected:
      int base_cost;
      int age;
      int cost;
      int income;
      int sick_cost;
      string actual_age;
      int new_revenue;
      int num_babies;
   public:
      Animal();
      Animal(int);
      int get_age();
      void set_age(int);
      int calc_age(int);
      int get_base_cost();
      void set_base_cost(int);
      int get_cost();
      void set_cost(int);
      int calc_food(int);
      void add_age();
      int get_income();
      void set_income(int);
      int get_sick_cost();
      void set_sick_cost(int);
      int get_new_revenue();
      void set_new_revenue(int);
      int increase_revenue(int);
      int get_num_babies();
      void set_num_babies(int);
};
#endif
