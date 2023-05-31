#include<iostream>
#include"event.h"
#include"gold.h"

using namespace std;

/****************************************************************
 * SETS THE PRECEPT FOR THE GOLD
 ****************************************************************/
void Gold::precept(){
   cout << "You see a glimmer nearby" << endl;
}
/****************************************************************
 * SHOWS THE ENCOUNTER PLAYER HAS WITH THE GOLD
 ****************************************************************/

void Gold::encounter(){
   cout << "you pick the gold" << endl;
}

/****************************************************************
 * Function: get_name
 * Description:this is used to get the event name 
 * Parameters:none
 * Pre-conditions:created in parent file
 * Post-conditions:returns letter
 ****************************************************************/
string Gold::get_name(){
   return "G";
}

/****************************************************************
 * Function: set_name
 * Description:this is used to set event name
 * Parameters:name
 * Pre-conditions:getter is created
 * Post-conditions:moves on to next object
 ****************************************************************/
void Gold::set_name(string name){
   this->name="G";
}
