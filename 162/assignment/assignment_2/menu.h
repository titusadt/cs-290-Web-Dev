/*************************************************************
 * Program:menu.h
 * Author:Temi
 * Date:4/28/29
 * Description:this holds my menu class and all my function prototypes
 * Input:nil
 * Output:nil
 ************************************************************/
#ifndef MENU_H
#define MENU_H
#include<iostream>
#include<string>
#include"pizza.h"

using namespace std;

class Menu{
   private:
      int num_pizzas;
      Pizza* pizzas;

   public:
      Menu();
      ~Menu();
      Menu (const Menu &m2);
      Menu &operator =(const Menu &m2);
      Menu search_pizza_by_ingridients_to_include(string* ingridients, int num_ingridients);
      Menu search_pizza_by_ingridients_to_exclude(string* ingridients, int num_ingridients);
      void add_to_menu(Pizza pizza_to_add);
      void remove_from_menu(int index_of_pizza_on_menu);
      int get_num_pizzas()const;
      void set_num_pizzas(int num_pizzas);
      Pizza* get_pizzas()const;
      void set_pizzas(int num_pizzas, Pizza* p);
      void read_pizza();
      Menu search_pizza_by_cost(int upper_bound, string size);
      int return_pizza_index(int index);
      void print();
};
#endif
