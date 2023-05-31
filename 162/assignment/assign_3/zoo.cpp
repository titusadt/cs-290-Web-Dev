#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include"zoo.h"
#include"animal.h"
#include"monkey.h"
#include"otter.h"
#include"meerkat.h"

using namespace std;


/***************************************************************
 * Function:Zoo()
 * Description:this is a constructor
 * Parameters:none
 * Pre-conditions: it is created in the interface file
 * Post-conditions:moves on to the next thing
 ***************************************************************/
Zoo::Zoo(){
   bank=100000;
   revenue=0;
   num_monkeys=0;
   num_otters=0;
   num_meerkats=0;
   monkeys = NULL;
   feed=0;
   otters=NULL;
   meerkats=NULL;
}


/***************************************************************
 * Function:Zoo
 * Description:this a copy constructor
 * Parameters:z2
 * Pre-conditions:it is created in the interface file
 * Post-conditions:moves on to the next thing
 ***************************************************************/
Zoo::Zoo(const Zoo &z2){
   bank=z2.bank;
   revenue=z2.revenue;
   num_monkeys=z2.num_monkeys;
   num_otters=z2.num_otters;
   num_meerkats=z2.num_meerkats;
   animals = new string[num_monkeys];
   for(int i=0; i<num_monkeys; i++){
     monkeys[i] = z2.monkeys[i];
   }
  for(int j=0; j<num_otters; j++){
      otters[j] = z2.otters[j];
   }
  for(int k=0; k<num_meerkats; k++){
      meerkats[k] = z2.meerkats[k];
   }
     
}


/***************************************************************
 * Function:&Zoo
 * Description:this is an asignment operator
 * Parameters:z2
 * Pre-conditions:it is created in the interface file
 * Post-conditions:moves on to the next thing
 ***************************************************************/
Zoo &Zoo::operator=(const Zoo &z2){
   if(monkeys != NULL){
   delete[]monkeys;
   }
   bank=z2.bank;
   revenue=z2.revenue;
   num_monkeys=z2.num_monkeys;
   animals = new string[num_monkeys];
   for(int i=0; i<num_monkeys; i++){
     monkeys[i] = z2.monkeys[i];
   }
  for(int j=0; j<num_otters; j++){
      otters[j] = z2.otters[j];
   }
  for(int k=0; k<num_meerkats; k++){
      meerkats[k] = z2.meerkats[k];
   
   }
   return *this;
}

/***************************************************************
 * Function:get_bank
 * Description:this gets the bank
 * Parameters:none
 * Pre-conditions:the bank is created in the animal class
 * Post-conditions:the program moves on to the setter
 ***************************************************************/
int Zoo::get_bank(){
   return bank;
}

/***************************************************************
 * Function:set_bank
 * Description:this sets the base cost
 * Parameters:base_cost
 * Pre-conditions:the base cost is created in the animal class
 * Post-conditions:the program moves on to the next thing
 ***************************************************************/
void Zoo::set_bank(int bank){
   this->bank=bank;
}

/***************************************************************
 * Function:get_num_monkeys
 * Description:this gets the number of monkeys
 * Parameters:none
 * Pre-conditions:the number of monkeys is created in the animal class
 * Post-conditions:the program moves on to the setter
 ***************************************************************/
int Zoo::get_num_monkeys()const{
   return num_monkeys;
}

/***************************************************************
 * Function:get_monkeys
 * Description:this gets the monkey array
 * Parameters:none
 * Pre-conditions:the monkey is created in the animal class
 * Post-conditions:the program moves on to the setter
 ***************************************************************/
Monkey* Zoo::get_monkeys()const{
   return monkeys;
}

/****************************************************************
 * Function: incremenent monkey
 * Description:used to add to the monkey array
 * Parameters:add_monkey
 * Pre-conditions: Monkey is defined
 * Post-conditions:moves to next thing
 ***************************************************************/
int Zoo::increment_monkey(Monkey add_monkey){
   Monkey* new_monkey = new Monkey[num_monkeys+1];
   for(int i=0; i < num_monkeys; i++){
      new_monkey[i]=monkeys[i];
   }
   new_monkey[num_monkeys]=add_monkey;
   num_monkeys++;
   delete [] monkeys;
   monkeys = new_monkey;
   return num_monkeys;
}

/****************************************************************
 * Function: incremenent otter
 * Description:used to add to the otter array
 * Parameters:add_otter
 * Pre-conditions: Otter is defined
 * Post-conditions:moves to next thing
 ***************************************************************/
int Zoo::increment_otter(Otter add_otters){
   Otter* new_otters = new Otter[num_otters+1];
   for(int i=0; i < num_otters; i++){
      new_otters[i]=otters[i];
   }
   new_otters[num_otters]=add_otters;
   num_otters++;
   delete [] otters;
   otters = new_otters;
   return num_otters;
}

/****************************************************************
 * Function: incremenent_meerkat
 * Description:used to add to the meerkat array
 * Parameters:add_meerkat
 * Pre-conditions: Meerkat is defined
 * Post-conditions:moves to next thing
 ***************************************************************/
int Zoo::increment_meerkat(Meerkat add_meerkat){
   Meerkat* new_meerkat = new Meerkat[num_meerkats+1];
   for(int i=0; i < num_meerkats; i++){
      new_meerkat[i]=meerkats[i];
   }
   new_meerkat[num_meerkats]=add_meerkat;
   num_meerkats++;
   delete [] meerkats;
   meerkats = new_meerkat;
   return num_meerkats;
}

/****************************************************************
 * Function: increase_m
 * Description:used to add to the number of monkeys
 * Parameters:
 * Pre-conditions: the increment_monkey function is created
 * Post-conditions:moves to next thing
 ***************************************************************/
void Zoo::increase_m(){
   int choice;
   Monkey m(730);
   this->increment_monkey(m);
   int cost = m.get_cost();
   bank -= cost;
   cout << "Your current bank is: " << bank << endl;
   cout << "Do you want to buy another monkey?(yes-1, no-2)" << endl;
   cin >>choice;
   if(choice==1){
      this->increment_monkey(m);
      bank -= cost;
	 }
	 cout << "Your current bank is: " << bank << endl;
}

/****************************************************************
 * Function: increase_ott
 * Description:used to add to the number of otters
 * Parameters:
 * Pre-conditions: the increment_otter function is created
 * Post-conditions:moves to next thing
 ***************************************************************/
void Zoo::increase_ott(){
   int choice;
   Otter ott(730);
	 this->increment_otter(ott);
	 int cost = ott.get_cost();
	 bank -= cost;
	 cout << "Your current bank is: " << bank <<endl;
	 cout << "Do you want to buy another otter?(yes-1, no-2): " << endl;
	 cin >>choice;
	 if(choice==1){
	    this->increment_otter(ott);
	    bank -= cost;
	    cout << "Your current bank is: " << bank << endl;
	 }
}

/****************************************************************
 * Function: increase_kat
 * Description:used to add to the number of meerkats
 * Parameters:
 * Pre-conditions: the increment_meerkat function is created
 * Post-conditions:moves to next thing
 ***************************************************************/
void Zoo::increase_kat(){
   int choice;
   Meerkat kat(730);
	 this->increment_meerkat(kat);
	 int cost = kat.get_cost();
	 bank -= cost;
	 cout << "Your current bank is: " << bank << endl;
	 cout << "Do you want to buy another meerkat?(yes-1, no-2)" << endl;
	 cin >>choice;
	 if(choice==1){
	    this->increment_meerkat(kat);
	    bank -= cost;
	    cout << "Your current bank is: " <<  bank << endl;
	 }
}

/****************************************************************
 * Function: purchase animal
 * Description:used to buy animal
 * Parameters:
 * Pre-conditions: the increment_meerkat function is created
 * Post-conditions:moves to next thing
 ***************************************************************/
void Zoo::purchase_animal(){
   Otter ott(730);
   Meerkat kat(730);
   Monkey m(730);
   string ans;
   int choice;
   cout << "Your current bank is: " << bank << endl;
   cout << "Do you want to purchase an animal? (y- yes, n - no)" << endl;
   cin >>ans;
   if(ans=="y"){
      cout << "What type of animal do you want to buy? (Monkey - 1, Otter - 2, Meerkat - 3)" << endl;
      cin >> choice;
      if(choice==1){
	 this->increase_m();
      }
      else if(choice==2){
	 this->increase_ott();
	 }
      
      else if(choice==3){
	 this->increase_kat();
}
}
}

/****************************************************************
 * Function: buy_feed
 * Description:used to buy food
 * Parameters:
 * Pre-conditions: the base _cost function is created
 * Post-conditions:moves to next thing
 ***************************************************************/
void Zoo::buy_feed(){
   int b;
   Animal a;
   Otter ott(730);
   Meerkat kat(730);
   Monkey m(730);
   int base_food = a.calc_food(b);
   if(num_monkeys>=1){
      int monkey_food= 4*base_food;
      cout << "monkey food is: " << monkey_food << endl;
      bank-=monkey_food;
   }
   if(num_otters>=1){
      int otter_food = 2*base_food;
      cout << "otter food is; " << otter_food << endl;
      bank-=otter_food;
   }
   if(num_meerkats>=1){
      int meerkat_food = base_food;
      cout << "meerkat food is; " << meerkat_food << base_food << endl;
      bank-=meerkat_food;
   }
   cout << "bank is: " << bank << endl;
   cout << "Food has been deducted form your bank." << endl;
   cout << "Current bank is: " << bank << endl;
}

/****************************************************************
 * Function: sickness
 * Description:used to pay for animal illness
 * Parameters:
 * Pre-conditions: the sick function is created
 * Post-conditions:moves to next thing
 ***************************************************************/
void Zoo::sickness(){
   Animal a;
   Otter ott(730);
   Meerkat kat(730);
   Monkey m(730);
   int sick_animal = rand()%3+1;
   if(sick_animal==1){
      cout << "A Meerkat has fallen sick, sick fees will be deducted" << endl;
      int sick_meerkat = kat.get_sick_cost();
      bank -= sick_meerkat;
      cout << "Your current bank is: " << bank << endl;
      
   }
   else if(sick_animal==2){
      cout << "An otter has fallen sick, sick fees will be deducted" << endl;
      int sick_otter = ott.get_sick_cost();
      bank -= sick_otter;
      cout << "Your current bank is: " << bank << endl;
   }
   else if(sick_animal==3){
      cout << "A Monkey has fallen sick, sick fees will be deducted" << endl;
      int sick_monkey = m.get_sick_cost();
      bank -= sick_monkey;
      cout << "Your current bank is: " << bank << endl;
   }
}

/****************************************************************
 * Function: vhange_revenue
 * Description:used to increase the monkey revenue
 * Parameters:
 * Pre-conditions: the new revenue function is created
 * Post-conditions:moves to next thing
 ***************************************************************/
void Zoo::change_revenue(){
   int b;
   Animal a;
   Monkey m(730);
   cout << "You get a boom in monkey revenue!" << endl;
   int new_monkey_revenue=m.increase_revenue(b);
   bank += new_monkey_revenue;
   cout << "New Monkey Revenue is: " << bank << endl;
}

/****************************************************************
 * Function: special event
 * Description:used to create a special event
 * Parameters:
 * Pre-conditions: the sicknes, birth and extra revenue function is created
 * Post-conditions:moves to next thing
 ***************************************************************/
void Zoo::special_event(){
   srand(time(NULL));
   int event = rand()%3+1;
   cout << "Special Event Occurs!"<< endl;
   if(event==1){
      this->sickness();
   }
   else if(event==2){
      this->change_revenue();
   }
   else if(event==3){
      cout << "A randomly chosen animal gets sick" << endl;
   }
}

/****************************************************************
 * Function:add_revenue
 * Description:used to add the revenue gotten from the animals
 * Parameters:
 * Pre-conditions: the revenue variable is created
 * Post-conditions:moves to next thing
 ***************************************************************/
void Zoo::add_revenue(){
   Animal a;
   Otter ott(730);
   Meerkat kat(730);
   Monkey m(730);
   if(num_monkeys>=1){
   int monkey_revenue = m.get_income();
   bank += monkey_revenue*num_monkeys;
   }
   if(num_otters>=1){
   int otter_revenue = ott.get_income();
   bank += otter_revenue*num_otters;
   }
   if(num_meerkats>=1){
   int meerkat_revenue = kat.get_income();
   bank += meerkat_revenue*num_meerkats;
   }
   cout << "Revenue has been added!" << endl;
   cout << "New bank is: " << bank << endl;
}

/****************************************************************
 * Function: check_bank
 * Description:ends game if the bank is less that 0
 * Parameters:
 * Pre-conditions: the game hase come to an end
 * Post-conditions:moves to next thing
 ***************************************************************/
void Zoo::check_bank(){
   if (bank==0){
      cout << "Your bank is 0 and the game has ended" << endl;
   }
}

/****************************************************************
 * Function: ~Zoo
 * Description:Destructor
 * Parameters:
 * Pre-conditions: Deletes arrays
 * Post-conditions:
 ***************************************************************/
Zoo::~Zoo(){
   delete [] monkeys;
   delete [] otters;
   delete [] meerkats;
}

