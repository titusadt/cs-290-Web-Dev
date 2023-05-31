/*************************************************************
 * Program:pizza.h
 * Author:Temi
 * Date:4/28/19
 * Description:this holdes my pizza class and all my function prototypes
 * Input:nil
 * Output:nil
 ************************************************************/
#ifndef PIZZA_H
#define PIZZA_H

#include<iostream>
#include<string>
using namespace std;

class Pizza{
   private:
      string name;
      int small_cost;
      int medium_cost;
      int large_cost;
      int num_ingridients;
      string *ingridients;
   public:
      Pizza();
      ~Pizza();
      Pizza (const Pizza &p2);
      Pizza &operator =(const Pizza &p2);
      string get_name()const;
      void set_name(string name);
      int get_num_ingridients()const;
      void set_num_ingridients(int num_ingridients);
      int get_small_cost()const;
      void set_small_cost(int small_cost);
      int get_medium_cost()const;
      void set_medium_cost(int medium_cost);
      int get_large_cost()const;
      void set_large_cost(int large_cost);
      string get_ingridients(int i)const;
      void set_ingridient(int index, string new_ingridient);
      bool sort_cost(int upper_bound);
      void add_ingridients(string ingrdients_to_add);
      void remove_ingridients(int index_of_ingrdients_on_menu);
};

#endif
