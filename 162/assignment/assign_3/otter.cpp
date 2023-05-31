#include<iostream>
#include"animal.h"
#include"otter.h"

using namespace std;

/***************************************************************
 * Function:Otter()
 * Description:this is a default contructor that sets all the inherited objects to 0
 * Parameters:none
 * Pre-conditions:the objects must have been created in the animal class
 * Post-conditions:the program moves on to the non-default constructor
 ***************************************************************/
Otter::Otter(){
   cost = 0;
   income =0;
   sick_cost=0;
   num_babies=0;
}


/***************************************************************
 * Function:Otter(int age)
 * Description:this is a non-default contructor that sets all the inherited objects to 0
 * Parameters:none
 * Pre-conditions:the objects must have been created in the animal class
 * Post-conditions:the program moves on to the next thing
 ***************************************************************/
Otter::Otter(int a) : Animal(a){
   cost = 5000;
   income = 250;
   sick_cost = 125;
   num_babies=2;
}
