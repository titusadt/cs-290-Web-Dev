#include<iostream>
#include"event.h"
#include"pit.h"

using namespace std;

/****************************************************************
 * SETS THE PRECEPT FOR THE GOLD
 ****************************************************************/
void Pit::precept(){
   cout << "You feel a breeze" << endl;
}

/****************************************************************
 * SHOWS THE ENCOUNTER PLAYER HAS WITH THE GOLD
 ****************************************************************/
void Pit::encounter(){
   cout << "You enter into a pit and die" << endl;
}

/****************************************************************
 * Function: get_name
 * Description:this is used to get the event name 
 * Parameters:none
 * Pre-conditions:created in parent file
 * Post-conditions:returns letter
 ****************************************************************/
string Pit::get_name(){
   return "P";
}

/****************************************************************
 * Function: set_name
 * Description:this is used to set event name
 * Parameters:name
 * Pre-conditions:getter is created
 * Post-conditions:moves on to next object
 ****************************************************************/
void Pit::set_name(string name){
   this->name="P";
}
