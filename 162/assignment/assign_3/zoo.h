#ifndef ZOO_H
#define ZOO_H
#include<iostream>
#include<string>
#include"monkey.h"
#include"animal.h"
#include"meerkat.h"
#include"otter.h"

using namespace std;

class Zoo{
   private:
      int bank;
      int revenue;
      int num_monkeys;
      int num_otters;
      int num_meerkats;
      int feed;
      string *animals;
      Monkey * monkeys;
      Otter *otters;
      Meerkat *meerkats;
   public:
      Zoo();
      ~Zoo();
      Zoo (const Zoo &z2);
      Zoo &operator =(const Zoo &z2);
      int get_bank();
      void set_bank(int);
      int increment_monkey(Monkey);
      int get_num_monkeys()const;
      Monkey* get_monkeys()const;
      int increment_otter(Otter);
      int get_num_otters()const;
      Otter* get_otters()const;
      int increment_meerkat(Meerkat);
      int get_num_meerkats()const;
      Monkey* get_meerkats()const;
      void purchase_animal();
      void increase_m();
      void increase_ott();
      void increase_kat();
      void buy_feed();
      void add_revenue();
      void sickness();
      void birth();
      void change_revenue();
      void special_event();
      void check_bank();
};


#endif
