/*****************************************************************
 * Program filename:Wumpus
 * Author:Temi
 * Date: 4/16/19
 * Description: I create an adventure game that lets the user find gold or kill a wumpus
 * Input: all of the command words
 * Output: the Grid after the players decisions
 ******************************************************************/
#include<iostream>
#include<vector>
#include"room.h"
#include<cstdlib>
#include<ctime>
#include"game.h"
#include"event.h"
#include"pit.h"
#include"state.h"
#include "bats.h"
#include "gold.h"
#include "wumpus.h"

using namespace std;
     
int main(int argc, char *argv[]){
   Game g;
   Event * event1 = new Pit();
   Event * event2 = new Pit();
   Event * event3 = new Bats();
   Event * event4 = new Bats();
   Event * event5 = new Gold();
   //Event * event6 = new Wumpus();
   vector <Room> rooms;
   srand(time(NULL));
   Room r;
   if(argc != 2){
      cout << "There is a problem" << endl;
      return 1;
   }
   int square_size=atoi(argv[1]);
   vector<vector<Room> > cave(square_size, vector<Room> (square_size));
   g.create_vector(square_size);
   Room & rm = g.get_empty_room(square_size);
   Room & rm1 = g.get_empty_room(square_size);
   Room & rm2 = g.get_empty_room(square_size);
   Room & rm3 = g.get_empty_room(square_size);
   Room & rm4 = g.get_empty_room(square_size);
   rm.set_event(event1);
   rm1.set_event(event2);
   rm2.set_event(event3);
   rm3.set_event(event4);
   rm4.set_event(event5);
   g.set_player(square_size);
   g.print_grid(square_size);
   while(true){
   g.move();
   g.print_grid(square_size);
   g.doing_events();
   }
   delete event1;
   delete event2;
   delete event3;
   delete event4;
   delete event5;
   
   return 0;
}

//strcompare thingie
