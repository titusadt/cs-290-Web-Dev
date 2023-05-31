#include<iostream>
#include"game.h"
#include"event.h"
#include"room.h"
#include<cstdlib>
#include<ctime>
#include"pit.h"
#include"bats.h"
#include"gold.h"
#include"wumpus.h"


using namespace std;
/****************************************************************
 * Gets temporary x-coordinate
 ****************************************************************/
int Game::get_tempx(){
   return tempx;
}

/****************************************************************
 *sets temporary x-coordinate
 ****************************************************************/
void Game::set_tempx(int tempx){
   this->tempx=tempx;
}

/****************************************************************
 * Gets temporary y-coordinate
 ****************************************************************/
int Game::get_temp_y(){
   return temp_y;
}

/****************************************************************
 * Sets temporary y-coordinate
 ****************************************************************/
void Game::set_temp_y(int temp_y){
   this->tempx=temp_y;
}

/****************************************************************
 * Function: get_empty_room
 * Description:this is used to get an empty room
 * Parameters:size
 * Pre-conditions:none
 * Post-conditions:returns coordinates
 ****************************************************************/
Room & Game::get_empty_room(int square_size){
   int x,y;
   Room  rm;
   do{
      x= rand()%square_size;
      y= rand()%square_size;
   }while(cave.at(x).at(y).get_event()!=NULL);
   return cave.at(x).at(y);
}

/****************************************************************
 * Function: create_vector
 * Description:this is used to create a 2d vector
 * Parameters:square_size
 * Pre-conditions:none
 * Post-conditions: returns cave
 ****************************************************************/
vector<vector<Room> > Game::create_vector(int square_size){
   for(int i=0; i<square_size; i++){
   	vector<Room> temp_room;
	for(int j = 0; j < square_size; j++){
		temp_room.push_back(Room());
	}
      	cave.push_back(temp_room);
   }
   return cave;
}

/****************************************************************
 * Function: print grid
 * Description:this is used to print the grid after every turn
 * Parameters:pass
 * Pre-conditions:2d vector is created
 * Post-conditions:none
 ****************************************************************/
void Game::print_grid(int square_size){
   for(int i=0; i<square_size; i++){
      for(int j=0; j<square_size; j++){
         cout << "+---";
      }
      cout << "+" << endl;
   for(int c =0; c<square_size; c++){
      cout << "|";
      if(cave[i][c].get_event()!= NULL){
	 if(st.player_x == i && st.player_y == c){
	    cout << " * ";
	 }
	 else {
	   cout << " "<<cave[i][c].get_name()<<" ";
	 
	 }
      }
      else{
	 if(st.player_x == i && st.player_y == c){
	  cout << " * ";
	 }
	 else{
	 cout << "   ";
	 }
	 }
      }
     cout << "|" << endl;
   }   
   for(int b=0; b<square_size; b++){
      cout << "+---";
      }
   cout << "+" << endl;
   
}

/****************************************************************
 * Function: set_plyaer
 * Description:this is used toset the players coordinates
 * Parameters:pass
 * Pre-conditions:none
 * Post-conditions:can be used after this
 ****************************************************************/
void Game::set_player(int square_size){
   Room rm;
   int x,y;
   do{
      x=rand()%square_size;
      y=rand()%square_size;
     }while(cave[x][y].get_event()!=NULL);
   st.player_x=x;
   st.player_y=y;  
}

/****************************************************************
 * Function: check_bounds
 * Description:this is used to check if the player is inside the grid
 * Parameters:size, index
 * Pre-conditions:player has been set
 * Post-conditions:player can be moved
 ****************************************************************/
bool Game::check_bounds(int square_size, int index){
   if(index ==1){
      if(tempx >= square_size || tempx <0){
         return false;
      }
      else{
	 st.player_x = tempx;
	 return true;
      }
   }
   else{
      if(temp_y >= square_size || temp_y <0){
	 return false;
      }
      else{
	 st.player_y = temp_y;
	 return true;
      }
   }
}

/****************************************************************
 * Function: move
 * Description: lets the player move on the gris
 * Parameters:pass
 * Pre-conditions:none
 * Post-conditions:game can be played
 ***************************************************************/
void Game::move(){
   char option;
   cout << "Enter the direction you want to move(w-north, a-west, s-south, d-east): " << endl;
   cin >> option;
   if (option == 'w'){
      check_bounds(st.square_size, st.player_x);
      st.player_x --;
   }
   else if(option == 's'){
      check_bounds(st.square_size, st.player_x);
      st.player_x ++;
   }
   else if(option == 'a'){
      check_bounds(st.square_size, st.player_y);
      st.player_y --;
   }
   else if(option == 'd'){
      check_bounds(st.square_size, st.player_y);
      st.player_y ++;
   }
   
}

/*void Game::shoot_arrows(){
   int ans;
   st.arrows=3;
   cout << "Enter the direction you want to shoot(w-north, a-west, s-south, d-east): " << endl;
   cin >> ans;


}

void Game::choose(){
   int ans;
   cout << "Do you want to move or shoot an arrow(1-move, 2-shoot)? " << endl;
   cin >> ans;
   if(ans == 1){
      move();   
   }
   else{
      shoot_arrows();
   }
}*/

/****************************************************************
 * Function: doing_events
 * Description: lets the player encounter events
 * Parameters:pass
 * Pre-conditions:none
 * Post-conditions:game can be played
 ***************************************************************/
void Game::doing_events(){
   Pit p;
   Bats b;
   Gold g;
   if(cave[st.player_x][st.player_y].get_name()== "P"){
      p.encounter();
   }
   else if(cave[st.player_x][st.player_y].get_name()== "B"){
      b.encounter();
   }
   else if(cave[st.player_x][st.player_y].get_name()== "G"){
      g.encounter();
   }
   }


