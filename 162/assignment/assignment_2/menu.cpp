/*************************************************************
 * Program:menu.cpp
 * Author:Temi
 * Date:4/28/19
 * Description:this is used to define all the necessary functions that are declred in my menu.h file.
 * Input:takes in use budget, and the ingridient the customer wants to sort by
 * Output:it prints out the corresponding menu based in the user input
 ************************************************************/
#include<iostream>
#include<string>
#include<fstream>
#include"menu.h"
#include"pizza.h"

using namespace std;

/****************************************************************
 * Function:Menu
 * Description:constructor
 * Parameters:none
 * Pre-conditions:Pizza class is created
 * Post-conditions:moves to next thing
 ****************************************************************/
Menu::Menu(){
   num_pizzas=0;
   pizzas=NULL;
}

/****************************************************************
 * Function:copy constructor
 * Description:used to copy the constructor
 * Parameters:none
 * Pre-conditions:constructor is made
 * Post-conditions:moves on to next thing
 ****************************************************************/
Menu::Menu(const Menu &m2){
   num_pizzas=m2.num_pizzas;
   pizzas= new Pizza[num_pizzas];
   for(int i=0; i<num_pizzas; i++){
      pizzas[i]=m2.pizzas[i];
   }
}

/****************************************************************
 * Function:assignment operator
 * Description:used to cope objects with an assignment operator
 * Parameters:Menu &2
 * Pre-conditions:copy constructor is mad
 * Post-conditions:moves on
 ****************************************************************/
Menu& Menu::operator=(const Menu &m2){
   delete [] pizzas;
   num_pizzas=m2.num_pizzas;
   pizzas= new Pizza[num_pizzas];
   for(int i=0; i<num_pizzas; i++){
      pizzas[i]=m2.pizzas[i];
   }
   
   return *this;
}
/****************************************************************
 * Function:get_num_pizzas
 * Description:used to get num_pizza
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:moves to set num
 ****************************************************************/
int Menu::get_num_pizzas()const{
   return num_pizzas;
}

/****************************************************************
 * Function:set_num_pizzas
 * Description:used to set num_pizza 
 * Parameters:string name
 * Pre-conditions:get name is defined
 * Post-conditions:moves to next object
 ****************************************************************/
void Menu::set_num_pizzas(int num_pizzas){
   this->num_pizzas=num_pizzas;
}

/****************************************************************
 * Function:get_pizzas
 * Description:used to get pizzas
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:moves to set pizza
 ****************************************************************/
Pizza* Menu::get_pizzas()const{
   return pizzas;
}

/****************************************************************
 * Function:set_pizzas
 * Description:used to set pizzas
 * Parameters:string name
 * Pre-conditions:get name is defined
 * Post-conditions:moves to next object
 ****************************************************************/
void Menu::set_pizzas(int num_pizzas, Pizza* p){
   if(pizzas!=NULL){
      delete[]pizzas;
   }
   pizzas=p;
   this->num_pizzas=num_pizzas;
}

/****************************************************************
 * Function:read_pizza
 * Description:used to read information from menu file
 * Parameters:none
 * Pre-conditions:getter and setters are created
 * Post-conditions:moves to next thing
 ***************************************************************/
void Menu::read_pizza(){
   int get_num_line=0, temp_int, index;
   string temp;
   ifstream pizza_file;
   pizza_file.open("menu.txt");
   do{
      get_num_line ++;
   }while(getline(pizza_file, temp));
   int file_line = get_num_line;
   pizza_file.close();

   pizza_file.open("menu.txt");
   pizzas=new Pizza[file_line];
   while(!pizza_file.eof()){
      	Pizza p;
         pizza_file >> temp;        
      	 p.set_name(temp);
	 pizza_file >> temp_int;
	 p.set_small_cost(temp_int);
	 pizza_file >> temp_int;
	 p.set_medium_cost(temp_int);
	 pizza_file >> temp_int;
	 p.set_large_cost(temp_int);
	 pizza_file >> temp_int;
	
         for(int j=0; j < temp_int; j++){
	    pizza_file >> temp;
	    p.add_ingridients(temp);

	 }
	 add_to_menu(p);
      }
}
/****************************************************************
 * Function:search_pizza_by_cost
 * Description:used to search pizza by cost
 * Parameters:upper bound, size
 * Pre-conditions:info is read from file
 * Post-conditions:moves to next thing
 ***************************************************************/

Menu Menu::search_pizza_by_cost(int upper_bound, string size){
   Menu new_menu=*this;
   cout << "What is your budget(in dollars)?" << endl; // TODO ask outside of function
   cin >> upper_bound;
   cout << "What is your size(S/M/L)?" << endl;
   cin >> size;
   for(int i=num_pizzas-1; i>=0; i--){
      if(size == "S" && pizzas[i].get_small_cost()>upper_bound){
	 new_menu.remove_from_menu(i);
	 }
      if(size == "M" && pizzas[i].get_medium_cost()>upper_bound){
	 new_menu.remove_from_menu(i);
      }
      if(size == "L" && pizzas[i].get_large_cost()>upper_bound){
	 new_menu.remove_from_menu(i);
      }
}
   return new_menu;
}


/****************************************************************
 * Function: add_to_menu
 * Description:used to add pizza to menu
 * Parameters:string pizza_to_add
 * Pre-conditions: menu is defined
 * Post-conditions:moves to next thing
 ***************************************************************/
void Menu::add_to_menu(Pizza pizza_to_add){
   Pizza* new_pizzas = new Pizza[num_pizzas+1];
   for(int i=0; i < num_pizzas; i++){
      new_pizzas[i]=pizzas[i];
   }
   new_pizzas[num_pizzas]=pizza_to_add;
   num_pizzas++;
   delete [] pizzas;
   pizzas = new_pizzas;
   
}

/****************************************************************
 * Function:search_pizza_by_ingridients_to_include
 * Description:used to to search by ingridients to include
 * Parameters:ingridientsn num_ingridients
 * Pre-conditions:igrdients are defined
 * Post-conditions:moves to next thing
 ***************************************************************/

Menu Menu::search_pizza_by_ingridients_to_include(string* ingridients, int num_ingridients){
   Menu new_menu;
    for(int i=0; i<num_ingridients; i++){
       for(int j=0; j<num_pizzas; j++){
          for(int k=0; k<pizzas[j].get_num_ingridients(); k++){
	     if(ingridients[i]==pizzas[j].get_ingridients(k)){
	        new_menu.add_to_menu(pizzas[j]);
		break;
	     }
	  }
       
       }
    }
   return new_menu;
}

/****************************************************************
 * Function:remove_from menu
 * Description:used to remove from menu
 * Parameters:int index_of_pizza_on_menu to add
 * Pre-conditions:igrdients are defined
 * Post-conditions:moves to next thing
 ***************************************************************/

void Menu::remove_from_menu(int index_of_pizza_on_menu){
   int j;
   Pizza* new_pizzas = new Pizza[num_pizzas-1];
   for(int i=0; i<num_pizzas; i++){
     if(i!= index_of_pizza_on_menu){
        new_pizzas[j]=pizzas[i];
	j++;
         }
   }
   delete[] pizzas;
   num_pizzas--;
   pizzas=new_pizzas;

}

/****************************************************************
 * Function:print
 * Description:used to print menu
 * Parameters:none
 * Pre-conditions:menu is sorted
 * Post-conditions:moves to next thing
 ***************************************************************/

void Menu::print(){
   for(int i=0; i<num_pizzas; i++){
      cout << pizzas[i].get_name() << " "<< pizzas[i].get_small_cost() << " " << pizzas[i].get_medium_cost() << " " << pizzas[i].get_large_cost() << " """;

      for(int j=0; j<pizzas[i].get_num_ingridients(); j++){
         cout << pizzas[i].get_ingridients(j) << " """;
      }
      cout << endl;
   }
}

/****************************************************************
 * Function:~Menu
 * Description:deconstructor
 * Parameters:none
 * Pre-conditions:Pizza pouters are deleted
 * Post-conditions:moves to next thing
 ***************************************************************/
Menu::~Menu(){
   if(pizzas!=NULL){
      delete [] pizzas;
   }
}

