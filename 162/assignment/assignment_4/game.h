#ifndef GAME_H
#define GAME_H
#include<iostream>
#include<vector>
#include"room.h"
#include"event.h"
#include "state.h"

using namespace std;

// create a game class that also has a vector of rooms and pass that in to your get empty room function

class Game{
   private:
      State st;
      vector<vector<Room> > cave;
      int tempx;
      int temp_y;
   public:
      int get_tempx();
      void set_tempx(int tempx);
      int get_temp_y();
      void set_temp_y(int temp_y);
      Room rm;
      Room & get_empty_room(int);
      vector<vector<Room> > create_vector(int);
      void set_player(int square_size);
      void set_actual_event();
      void print_grid(int);
      void shoot_arrows();
      bool check_bounds(int,int);
      void move();
      void choose();
      void doing_events();
};
#endif
