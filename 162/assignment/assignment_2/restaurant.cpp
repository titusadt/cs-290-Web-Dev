/*************************************************************
 * Program:restaurant.cpp
 * Author:Temi
 * Date:4/28/19
 * Description:thid is where i define all the functions in my restaurant.h file and i call other functions in it to complete the prog   ram.
 * Input:takes in all necessary using input like the order information and employee information.
 * Output:all the commands/instructions needed by the user to organise the page
 ************************************************************/
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include"restaurant.h"
#include"menu.h"
#include"pizza.h"

using namespace std;

/****************************************************************
 * Function:Restaurant
 * Description:constructor
 * Parameters:none
 * Pre-conditions:Restaurant class is created
 * Post-conditions:moves to next thing
 ****************************************************************/
Restaurant::Restaurant(){
   employees=NULL;
   week=NULL;
   name="";
   phone="";
   address="";
   num_employees=0;
}

/****************************************************************
 * Function:copy constructor
 * Description:used to copy the constructor
 * Parameters:none
 * Pre-conditions:constructor is made
 * Post-conditions:moves on to next thing
 ****************************************************************/
Restaurant::Restaurant(const Restaurant &r2){
   name=r2.name;
   phone=r2.phone;
   address=r2.address;
   num_employees=r2.num_employees;
   employees=new employee[num_employees];
   for(int i=0; i< num_employees; i++){
       employees[i]=r2.employees[i];
   }
   week=new hours[7];
   for(int j=0; j<7; j++){
      week[j]=r2.week[j];
   }
}
      

/****************************************************************
 * Function:assignmet operatore
 * Description:used to copy with the assignment operattor
 * Parameters:none
 * Pre-conditions:constructor is made
 * Post-conditions:moves on to next thing
 ****************************************************************/
Restaurant &Restaurant::operator=(const Restaurant &r2){
   if(employees !=NULL){
      delete []employees;
   }
   if(week !=NULL){
      delete [] week;
   }
   name=r2.name;
   phone=r2.phone;
   address=r2.address;
   num_employees=r2.num_employees;
   employees=new employee[num_employees];
   for(int i=0; i< num_employees; i++){
       employees[i]=r2.employees[i];
   }
   week=new hours[7];
   for(int j=0; j<7; j++){
      week[j]=r2.week[j];
   }
}/****************************************************************
 * Function:get_menu
 * Description:used to get menu
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:moves to set menu
 ****************************************************************/
Menu Restaurant::get_menu()const{
   return menu;
}
/****************************************************************
 * Function:set_menu
 * Description:used to set menu
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:moves to next thing
 ****************************************************************/
void Restaurant::set_menu(Menu menu){
   this->menu=menu;
}
/****************************************************************
 * Function:load_data
 * Description:used to read data from files
 * Parameters:none
 * Pre-conditions:getters and setter are made
 * Post-conditions:moves to next thing
 ****************************************************************/
void Restaurant::load_data(){
   int get_num_line=0;
   string temp;
   ifstream employee_file;
   employee_file.open("employee.txt");
   do{
      get_num_line ++;
   }while(getline(employee_file, temp));
   cout <<get_num_line << endl;
   employee_file.close();
   employees=new employee[get_num_line];
   employee_file.open("employee.txt");
   int i;
   while(!employee_file.eof()){
      employee_file >> employees[i].id;
      employee_file >> employees[i].password;
      employee_file >> employees[i].first_name;
      employee_file >> employees[i].last_name;
   i++;
   }
   

}

/*string Restaurant::read_week(){
   
}

void Restaurant::set_week(hours* week){
   this->week=week;
}*/
/****************************************************************
 * Function:get_name
 * Description:used to get name
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:moves to set name
 ****************************************************************/
string Restaurant::get_name()const{
   return name;
}
/****************************************************************
 * Function:set_name
 * Description:used to set_name
 * Parameters:string name
 * Pre-conditions:name gette
 * Post-conditions:moves to get phone
 ****************************************************************/
void Restaurant::set_name(string name){
   this->name=name;
}
/****************************************************************
 * Function:get_phone
 * Description:used to get phone
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:moves to set phone
 ****************************************************************/
string Restaurant::get_phone()const{
   return phone;
}
/****************************************************************
 * Function:set_phone
 * Description:used to set phone
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:moves to get address
 ****************************************************************/
void Restaurant::set_phone(string phone){
   this->phone=phone;
}
/****************************************************************
 * Function:get_address
 * Description:used to get address
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:moves to set address
 ****************************************************************/
string Restaurant::get_address()const{
   return address;
}
/****************************************************************
 * Function:set_week
 * Description:used to set week
 * Parameters:none
 * Pre-conditions:none
 * Post-conditions:moves to load data
 ****************************************************************/
void Restaurant::set_week(string address){
   this->address=address;
}


/*void Restaurant::choose(){
   Menu m;
   string ans, option;
   cout << "Welcome to Bytes Pizza!" << endl;
   cout << "Are you a customer(C), employee (E) or  would you like to quit(Q)?" << endl;
   cin>> ans;
   if (ans=="C"){
      cout << "What would you like to do?" << endl;
      cout << "1. View Menu" << endl;
      cout << "2. Search by cost" << endl;
      cout << "3. Search by ingridient" << endl;
      cout << "4. Place order" << endl;
      cout << "5. View hours" << endl;
      cout << "6. View Address" << endl;
      cout << "7. View Phone" << endl;
      cout << "8. Log out" << endl;
      cin >> option;
   }
   if(option == 1){
      cout << m.print() << endl;
   
   }


}*/

/****************************************************************
 * Function:~Resaturant
 * Description:deconstructor
 * Parameters:none
 * Pre-conditions:Restaurant pouters are deleted
 * Post-conditions:moves to next thing
 ***************************************************************/
Restaurant::~Restaurant(){
   if(employees !=NULL){
      delete []employees;
   }
   if(week !=NULL){
      delete [] week;
   }
}


