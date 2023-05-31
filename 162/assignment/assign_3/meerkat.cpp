#include<iostream>
#include<string>
#include"animal.h"
#include"meerkat.h"

using namespace std;


/***************************************************************
 * Function:Meerkat()
 * Description:this is a default contructor that sets all the inherited objects to 0
 * Parameters:none
 * Pre-conditions:the objects must have been created in the animal class
 * Post-conditions:the program moves on to the non-default constructor
 ***************************************************************/
Meerkat::Meerkat(){
   cost=0;
   income=0;
   sick_cost=0;
   num_babies=0;
}


/***************************************************************
 * Function:Meerkat(int age)
 * Description:this is a non-default contructor that sets all the inherited objects to 0
 * Parameters:none
 * Pre-conditions:the objects must have been created in the animal class
 * Post-conditions:the program moves on to the next thing
 ***************************************************************/
Meerkat::Meerkat(int age){
    cost = 500;
    income = 25;
    sick_cost = 13;
    num_babies=5;

}
