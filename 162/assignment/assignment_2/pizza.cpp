/*************************************************************
 * Program:pizza.cpp
 * Author:Temi
 * Date:4/28/2019
 * Description:this is to define all the necessary functions that are created in my pizza class
 * Input:nil
 * Output:nil
 ************************************************************/
#include<iostream>
#include<fstream>
#include<string>
#include"pizza.h"
#include"menu.h"
using namespace std;

/****************************************************************
 * Function:Pizza
 * Description:constructor
 * Parameters:none
 * Pre-conditions:Pizza class is created
 * Post-conditions:moves to next thing
 ****************************************************************/
Pizza::Pizza(){
   name="";
   small_cost=0;
   medium_cost=0;
   large_cost=0;
   num_ingridients=0;
   ingridients=NULL;
}
/****************************************************************
 * Function:copy constructor
 * Description:used to copy the constructor
 * Parameters:none
 * Pre-conditions:constructor is made
 * Post-conditions:moves on to next thing
 ****************************************************************/
Pizza::Pizza(const Pizza &p2){
   name=p2.name;
   small_cost =p2.small_cost;
   medium_cost =p2.medium_cost;
   large_cost=p2.large_cost;
   num_ingridients=p2.num_ingridients;
   ingridients = new string[num_ingridients];
   for(int i=0; i<num_ingridients; i++){
     ingridients[i] = p2.ingridients[i];
   }

}

/****************************************************************
 * Function:assignment operator
 * Description:used to cope objects with an assignment operator
 * Parameters:Pizza &2
 * Pre-conditions:copy constructor is mad
 * Post-conditions:moves on
 ****************************************************************/
Pizza &Pizza::operator=(const Pizza &p2){
   //check befor deleting (if ingridient is not equal to NUll)
   delete[]ingridients;
   name=p2.name;
   small_cost=p2.small_cost;
   medium_cost=p2.medium_cost;
   large_cost=p2.large_cost;
   num_ingridients= p2.num_ingridients;
   ingridients = new string[num_ingridients];
   for(int i=0; i<num_ingridients; i++){
     ingridients[i] = p2.ingridients[i];
   }

}

/****************************************************************
 * Function:get_name
 * Description:used to get pizza _name
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:moves to set name
 ****************************************************************/
string Pizza::get_name()const{
   return name;
}

/****************************************************************
 * Function:set_name
 * Description:used to set pizza namr
 * Parameters:string name
 * Pre-conditions:get name is defined
 * Post-conditions:moves to next object
 ****************************************************************/
void Pizza::set_name(string name){
   this->name=name;
}

/****************************************************************
 * Function:get_small_cost
 * Description:used to get small_cost
 * Parameters:none
 * Pre-conditions:name is set
 * Post-conditions:moves to set small name
 ****************************************************************/
int Pizza::get_small_cost()const{
   return small_cost;
}
/****************************************************************
 * Function:set_small_cost
 * Description:used to set small cost
 * Parameters:int small_cost
 * Pre-conditions:get small_cost is defined
 * Post-conditions:moves to next object
 ****************************************************************/
void Pizza::set_small_cost(int small_cost){
   this->small_cost=small_cost;
}
/****************************************************************
 * Function:get_medium cost
 * Description:used to get medium cost
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:moves to set medium cost
 ****************************************************************/

int Pizza::get_medium_cost()const{
   return medium_cost;
}
/****************************************************************
 * Function:set_medium
 * Description:used to set medium cost
 * Parameters:int medium cost
 * Pre-conditions:get medium xost is defined
 * Post-conditions:moves to next object
 ****************************************************************/

void Pizza::set_medium_cost(int medium_cost){
   this->medium_cost=medium_cost;
}
/****************************************************************
 * Function:large cost
 * Description:used to get large cost
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:moves to set large cost
 ****************************************************************/

int Pizza::get_large_cost()const{
   return large_cost;
}
/****************************************************************
 * Function:set_large cost
 * Description:used to set large cost
 * Parameters:int large cost
 * Pre-conditions:get large cost is defined
 * Post-conditions:moves to next object
 ****************************************************************/

void Pizza::set_large_cost(int large_cost){
   this->large_cost=large_cost;
}
/****************************************************************
 * Function:get_nu,_ingridients
 * Description:used to get number of ingrdients
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:moves to get ingrdients
 ****************************************************************/

int Pizza::get_num_ingridients()const{
   return num_ingridients;
}
/****************************************************************
 * Function:get_ingrdients
 * Description:used to get ingridients
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:moves to deconstructoe
 ****************************************************************/

string Pizza::get_ingridients(int i)const{
   return ingridients[i];
}

/****************************************************************
 * Function:~Pizza
 * Description:deconstructor
 * Parameters:none
 * Pre-conditions:Pizza pouters are deleted
 * Post-conditions:moves to next thing
 ***************************************************************/

Pizza::~Pizza(){
   delete[]ingridients;

}

/****************************************************************
 * Function: add_ingrideints
 * Description:used to andd ingrdidents to pizza
 * Parameters:string ingridients_to_add
 * Pre-conditions: ingridienst is defined
 * Post-conditions:moves to next thing
 ***************************************************************/
void Pizza::add_ingridients(string ingridients_to_add){
   string* new_ingridients = new string[num_ingridients+1];
   for(int i=0; i < num_ingridients; i++){
      new_ingridients[i]=ingridients[i];
   }
   new_ingridients[num_ingridients]=ingridients_to_add;
   num_ingridients++;
   delete [] ingridients;
   ingridients = new_ingridients;
}
/****************************************************************
 * Function:remove_ignriedients
 * Description:used to remvove ingridients
 * Parameters:int index_of ingrideites to add
 * Pre-conditions:igrdients are defined
 * Post-conditions:moves to next thing
 ***************************************************************/

void Pizza::remove_ingridients(int index_of_ingrdients_on_menu){
   int j;
   string* new_ingridients = new string[num_ingridients-1];
   for(int i=0; i<num_ingridients; i++){
     if(i!= index_of_ingrdients_on_menu){
        new_ingridients[j]=ingridients[i];
	j++;
         }
   }
   delete[] ingridients;
   num_ingridients--;
   ingridients=new_ingridients;

}
