#include<iostream>
#include<string>
#include"animal.h"
#include"monkey.h"

using namespace std;

/***************************************************************
 * Function:Monkey()
 * Description:this is a default contructor that sets all the inherited objects to 0
 * Parameters:none
 * Pre-conditions:the objects must have been created in the animal class
 * Post-conditions:the program moves on to the non-default constructor
 ***************************************************************/
Monkey::Monkey(){
    cost = 0;
    income=0;
    sick_cost=0;
    num_babies=0;
}

/***************************************************************
 * Function:Monkey()
 * Description:this is a non-default contructor that sets all the inherited objects to their actual values
 * Parameters:none
 * Pre-conditions:the objects must have been created in the animal class
 * Post-conditions:the program mives on to the next thing
 ***************************************************************/
Monkey::Monkey(int a) : Animal(a){    
    cost = 15000;
    sick_cost = 7500;
    num_babies=1;
}

