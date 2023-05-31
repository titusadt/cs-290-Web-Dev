#include<iostream>
#include"room.h"

using namespace std;

/****************************************************************
 * Function: Room
 * Description:constructor
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:
 ****************************************************************/
Room::Room(){
   event=NULL;
}

/****************************************************************
 * Function: get_name
 * Description:this is used to get event name
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:returns event name
 ****************************************************************/
string Room::get_name(){
   if(event != NULL){
      return event->get_name();
   }

   return " ";
}

/****************************************************************
 * Function: get_event
 * Description:this is used to get the event
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:returns the event
 ****************************************************************/
Event* Room::get_event(){
   return event;
}

/****************************************************************
 * Function: set_event
 * Description:this is used to set the event
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions: event can be used
 ****************************************************************/
void Room::set_event(Event* event){
   this->event=event;
}

