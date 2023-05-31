#include<iostream>
#include"event.h"
#include"wumpus.h"
#include<cstdlib>
#include<ctime>

using namespace std;

/****************************************************************
 * SETS THE PRECEPT FOR THE WUMPUS
 ****************************************************************/
void Wumpus::precept(){
   cout << "You smell a terrible stench" << endl;
}

/****************************************************************
 * SHOWS THE ENCOUNTER PLAYER HAS WITH THE WUMPUS
 ****************************************************************/
void Wumpus::encounter(){
   cout << "you die" << endl;
}

/****************************************************************
 * Function: get_name
 * Description:this is used to get the event name 
 * Parameters:none
 * Pre-conditions:created in parent file
 * Post-conditions:returns letter
 ****************************************************************/
string Wumpus::get_name(){
   return "W";
}

/****************************************************************
 * Function: set_name
 * Description:this is used to set event name
 * Parameters:name
 * Pre-conditions:getter is created
 * Post-conditions:moves on to next object
 ****************************************************************/
void Wumpus::set_name(string name){
   this->name="W";
}
