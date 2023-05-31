#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include"animal.h"

using namespace std;


/***************************************************************
 * Function:Animal()
 * Description:this is a non-default contructor that sets all the inherited objects to 0
 * Parameters:none
 * Pre-conditions:the objects must have been created in the animal class
 * Post-conditions:the program moves on to the non-default constructor
 ***************************************************************/
Animal::Animal(){
   base_cost =0;
   age =0;
   cost =0;
}


/***************************************************************
 * Function:Animal(int age)
 * Description:this sets the age
 * Parameters:age
 * Pre-conditions:the age i created in the animal class
 * Post-conditions:the program moves on to the getter and setters
 ***************************************************************/
Animal::Animal(int age){
    this->age = age;
}

//When buying a monkey, do this: Monkey mon(2); and then increment_monkey(mon);
/***************************************************************
 * Function:get_base_cost
 * Description:this gets the base cost
 * Parameters:none
 * Pre-conditions:the base cost i created in the animal class
 * Post-conditions:the program moves on to the setter
 ***************************************************************/
int Animal::get_base_cost(){
   return base_cost;
}

/***************************************************************
 * Function:set_base_cost
 * Description:this sets the base cost
 * Parameters:base_cost
 * Pre-conditions:the base cost is created in the animal class
 * Post-conditions:the program moves on to the next thing
 ***************************************************************/
void Animal::set_base_cost(int base_cost){
   this->base_cost=base_cost;
}

/***************************************************************
 * Function:get_age
 * Description:this gets the age
 * Parameters:none
 * Pre-conditions:the age is created in the animal class
 * Post-conditions:the program moves on to the next thing
 ***************************************************************/
int Animal::get_age(){
   return age;
}

/***************************************************************
 * Function:get_cost
 * Description:this gets the cost
 * Parameters:none
 * Pre-conditions:the  cost is created in the animal class
 * Post-conditions:the program moves on to the next thing
 ***************************************************************/
int Animal::get_cost(){
   return cost;
}

/***************************************************************
 * Function:get_income
 * Description:this gets the animals income
 * Parameters:none
 * Pre-conditions:the income is created in the animal class
 * Post-conditions:the program moves on to the setter
 ***************************************************************/
int Animal::get_income(){
   return income;
}

/***************************************************************
 * Function:set_base_cost
 * Description:this sets the base cost
 * Parameters:base_cost
 * Pre-conditions:the base cost is created in the animal class
 * Post-conditions:the program moves on to the next thing
 ***************************************************************/
void Animal::set_income(int income){
   this->income=income;
}

/***************************************************************
 * Function:get_sick_cost
 * Description:this gets the sick cost
 * Parameters:none
 * Pre-conditions:the base cost is created in the animal class
 * Post-conditions:the program moves on to the setter
 ***************************************************************/
int Animal::get_sick_cost(){
   return sick_cost;
}

/***************************************************************
 * Function:set_base_cost
 * Description:this sets the base cost
 * Parameters:base_cost
 * Pre-conditions:the base cost is created in the animal class
 * Post-conditions:the program moves on to the next thing
 ***************************************************************/
void Animal::set_sick_cost(int sick_cost){
   this->sick_cost=sick_cost;
}

/***************************************************************
 * Function:get_new_revenue
 * Description:this gets the new animal revenue
 * Parameters:none
 * Pre-conditions:the new revenue is created in the animal class
 * Post-conditions:the program moves on to the setter
 ***************************************************************/
int Animal::get_new_revenue(){
   return new_revenue;
}


/***************************************************************
 l.* Function:set_new_revenue
 * Description:this sets the new revenue
 * Parameters:new_revenue
 * Pre-conditions:the new_revenue is created in the animal class
 * Post-conditions:the program moves on to the next thing
 ***************************************************************/
void Animal::set_new_revenue(int new_revenue){
   this->new_revenue=new_revenue;
}

/***************************************************************
 * Function:get_num_babies
 * Description:this gets the number of babies each animal gives birth to
 * Parameters:none
 * Pre-conditions:the number of babies is  created in the animal class
 * Post-conditions:the program moves on to the setter
 ***************************************************************/
int Animal::get_num_babies(){
   return num_babies;
}

/***************************************************************
 * Function:set_num_babies
 * Description:this sets the new number of babies
 * Parameters:num_babies
 * Pre-conditions:the number of babies is created in the animal class
 * Post-conditions:the program moves on to the next thing
 ***************************************************************/
void Animal::set_num_babies(int num_babies){
   this->num_babies=num_babies;
}


/***************************************************************
 * Function:increment_revenue
 * Description:generates the new monkey revenue
 * Parameters:new_revenue
 * Pre-conditions:the new revenue is created in the animal class
 * Post-conditions:the program moves on to the next thing
 ***************************************************************/
int Animal::increase_revenue(int new_revenue){
   new_revenue = (rand()%401)+300;
   cout << "new revenue is: " << new_revenue << endl;
   return new_revenue;
   }

/***************************************************************
 * Function:calc_food
 * Description: calculates the food cost
 * Parameters:base cost
 * Pre-conditions:the base cost is created in the animal class
 * Post-conditions:the program moves on to the next thing
 ***************************************************************/
int Animal::calc_food(int base_cost){
   srand(time(NULL));
   base_cost =40;
   base_cost = (rand()%51)+75;
   cout << base_cost << endl;
   return base_cost;
}

/***************************************************************
 * Function:calc_age
 * Description:this sets the number of ages for the animals
 * Parameters:age
 * Pre-conditions:the age is created in the animal class
 * Post-conditions:the program moves on to the next thing
 ***************************************************************/
int Animal::calc_age(int age){
   if(age>=730){
      return 1;
   }
   if(age >35 || age < 730){
      return 2;
   }
   else{
      return 3;
   }
}

/***************************************************************
 * Function:add_age
 * Description:this add to the age of the animal each week
 * Parameters:none
 * Pre-conditions:it is created in the interface file
 * Post-conditions:moves on to the next thing
 ***************************************************************/
void Animal::add_age(){
   age+=7;
}

