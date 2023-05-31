#include<iostream>
#include"event.h"
#include"bats.h"

using namespace std;

/****************************************************************
 * SETS THE PRECEPT FOR THE BATS
 ****************************************************************/
void Bats::precept(){
   cout << "You hear wings flapping" << endl;
}

/****************************************************************
 * SHOWS THE ENCOUNTER PLAYER HAS WITH THE BATS
 ****************************************************************/
void Bats::encounter(){
   cout << "you are moved to another room" << endl;
}

/****************************************************************
 * Function: get_name
 * Description:this is used to get the event name 
 * Parameters:none
 * Pre-conditions:created in parent file
 * Post-conditions:returns letter
 ****************************************************************/
string Bats::get_name(){
   return "B";
}

/****************************************************************
 * Function: set_name
 * Description:this is used to set event name
 * Parameters:name
 * Pre-conditions:getter is created
 * Post-conditions:moves on to next object
 ****************************************************************/
void Bats::set_name(string name){
   this->name="B";
}
