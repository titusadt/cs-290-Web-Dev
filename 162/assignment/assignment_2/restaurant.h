/*************************************************************
 * Program:restaurant.h
 * Author:Temi
 * Date:4/28/19
 * Description:this holds everything in my restaurant class and also my employee and hours struct
 * Input:nil
 * Output:nil
 ************************************************************/
#ifndef RESTAURANT_H
#define RESTAURANT_H
#include<iostream>
#include<string>
#include"pizza.h"
#include"menu.h"

using namespace std;

struct employee{
   int id;
   string password;
   string first_name;
   string last_name;
};

struct hours{
   string day;
   string open_hour;
   string close_hour;
};

class Restaurant{
   private:
      Menu menu;
      employee* employees;
      hours* week;
      string name;
      string phone;
      string address;
      int num_employees;
   public:
      Restaurant();
      ~Restaurant();
      Restaurant(const Restaurant &r2);
      Restaurant &operator=(const Restaurant &r2);
      
      void load_data();
      bool login(int id, string password);
      void view_menu();
      void view_hours();
      void view_address();
      void view_phone();
      void search_menu_by_price();
      void search_by_ingridient();
      void change_hours();
      void add_to_menu();
      void remove_from_menu();
      void view_orders();
      void remove_orders();
      string get_name()const;
      void set_name(string name);
      string get_phone()const;
      void set_phone(string phone);
      string get_address()const;
      void set_week(string address);
      Menu get_menu()const;
      void set_menu(Menu menu);
      employee get_employees()const;
      void set_employees(employee* employees);
      void read_employees();
      //void choose();
};











#endif
