/*****************************************************************
 * Program filename: wizard.cpp
 * Author:Temi
 * Date: 4/16/19
 * Description: I define all my functions and perform all the processes that are needed.
 * Input: It takes in the user ID, Password and allows the user to choose what process they want to happen.
 * Output: It prints out the needed information.
 ******************************************************************/
#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
#include"wizard.h"

using namespace std;

/****************************************************************
 * Function: get_id
 * Description:this is used to get the user ID and password
 * Parameters:pass
 * Pre-conditions:none
 * Post-conditions:after this it checks if the typed in id and password matches with what is in the textfiles
 ****************************************************************/
int get_id(string *pass){

   int i;
   string wiz_id;
   bool error;
   do{
      cout << "Enter your user ID " << endl;
      getline(cin,wiz_id);
      error = false;
      for(int i=0; i < wiz_id.size(); i++){
	 if(!(wiz_id.at(i)>= '0' && wiz_id.at(i) <= '9')){
	    cout << "Error"<<endl;
	    error = true;
	    break;
	 }
	
      }
   
   }while(error);
   int wiz_idd = stoi(wiz_id);         //this is done to change the string to an array

   cout << "Enter your password: " << endl;
   cin >> *pass;
   cin.clear();
   cin.ignore(100, '\n');
   
   return wiz_idd;
}

/****************************************************************
 * Function:check_id
 * Description:this checks if the ID nad the password that is entered correspods with the information in the textfiles
 * Parameters:wiz_ar, get, num_wizards, pass
 * Pre-conditions:it needs the ID and Password to be typed in
 * Post-conditions:it then allows the user to choose what option they want
 ****************************************************************/
bool check_id(struct wizard *wiz_ar, int get, int num_wizards, string *pass){
   int check=true;
   while(check ==true){
   for(int c=0; c<num_wizards; c++){
      if(get==wiz_ar[c].id && *pass == wiz_ar[c].password){           //checking if the ID and passwords exist in the textfiles 
	 cout << "Welcome " << wiz_ar[c].name << endl;
	 cout << "ID: " << wiz_ar[c].id << endl;
	 cout << "Status: " << wiz_ar[c].position_title <<endl;
	 cout << "Beard length: " << wiz_ar[c].beard_length << endl;
         if(wiz_ar[c].position_title=="Student"){                    //checking if the user is a student
	    return true;
	 }
      }
   }
      
	 cout << "Invalid ID or Password" << endl;
         get = get_id(pass);
      
      

   }
}


/****************************************************************
 * Function:creat_spellbook
 * Description:used to create the spellbook array
 * Parameters:num_spellbook
 * Pre-conditions:none
 * Post-conditions:after it is created you assign the members
 ****************************************************************/
struct spellbook *create_spellbook(int num_spellbook){
   return new struct spellbook[num_spellbook];

}

/****************************************************************
 * Function:get_spellbook_data
 * Description:used to assign the members of the struct to the spellbook array
 * Parameters:spellbook_ar, num_spellbook,ifs2
 * Pre-conditions:the spellbook array has to be created
 * Post-conditions:after thisthe spell array is creeated
 ****************************************************************/
void get_spellbook_data(spellbook * spellbook_ar, int num_spellbook, ifstream & ifs2){
   for(int i=0; i<num_spellbook; i++){
      ifs2 >> spellbook_ar[i].title;
      ifs2 >> spellbook_ar[i].author;
      ifs2 >> spellbook_ar[i].num_pages;
      ifs2 >> spellbook_ar[i].edition;
      ifs2 >> spellbook_ar[i].num_spells;
      spellbook_ar[i].s= create_spells(spellbook_ar[i].num_spells);
      get_spell_data(spellbook_ar[i].s, spellbook_ar[i].num_spells, ifs2);
   

     float currentsuc = 0;
      for(int b=0; b<spellbook_ar[i].num_spells; b++){
         currentsuc += spellbook_ar[i].s[b].success_rate;                                //assigning the success_rate to a variable
   	}
      spellbook_ar[i].avg_success_rate = currentsuc/spellbook_ar[i].num_spells;          //calculating the average succes_rate
   }
}

/****************************************************************
 * Function:create_spells
 * Description:it is used to create a spell array
 * Parameters:num_spells
 * Pre-conditions:the members of the spellbiik struct are filled
 * Post-conditions:assign the members of the spell srray/struct
 ****************************************************************/
spell * create_spells(int num_spells){
   spell* temp = new spell[num_spells];
   return temp;

}

/****************************************************************
 * Function:get_spell_data
 * Description:this used to assign the members of the cell struct to the spell array
 * Parameters:s,num_spells, ifs2
 * Pre-conditions:the spell array is created
 * Post-conditions:it moves to the choose function
 ****************************************************************/
void get_spell_data(spell * s, int num_spells, ifstream & ifs2){
   for(int i=0; i< num_spells; i++){
      ifs2 >> s[i].name;
      ifs2 >> s[i].success_rate;
      ifs2 >> s[i].effect;
   }
}

/****************************************************************
 * Function:choose
 * Description:this is used to allow the user choose what they want to do with the spellbooks
 * Parameters:spellbook_ar, num_spellbook, s, num_spells, isStudent
 * Pre-conditions:all the arrays are created and mmembers are assigned
 * Post-conditions:it prints data out
 ****************************************************************/
void choose(spellbook * spellbook_ar, int num_spellbook, spell *s, int num_spells, bool isStudent){
   int pick;
   while(true){
   cout << "Which option would you like to choose? " << endl;
   cout << "Sort spellbook by number of pages(press 1): " << endl;
   cout << "Group spells by their effect(Press 2): " << endl;
   cout << "Sort spellbook by actual success rate(Press 3): " << endl;
   cout << "Quit(Press 4): " << endl;
   cin >> pick;
   if(pick ==1){
      spellbook_pages(spellbook_ar, num_spellbook);
   }
   else if(pick==2){
     sort_spell_effect(s, num_spells, spellbook_ar, num_spellbook, isStudent);   
   }
   else if(pick ==3){
      sort_success_rate(spellbook_ar, num_spellbook);
   }
   else if(pick ==4){
      return;
   }
   }


}

/****************************************************************
 * Function:spellbook_pages
 * Description:used to sort the spellbook by number of pages
 * Parameters:spellbook_ar, num_spellbook
 * Pre-conditions:the choose function has to be created
 * Post-conditions:the user is given the option of repeating
 ****************************************************************/
void spellbook_pages(spellbook * spellbook_ar, int num_spellbook){
   for(int i=0; i<num_spellbook; i++){
      for(int c=0; c<num_spellbook-1; c++){
	 if(spellbook_ar[c].num_pages > spellbook_ar[c+1].num_pages){
	    int swap = spellbook_ar[c].num_pages;
	    spellbook_ar[c].num_pages = spellbook_ar[c+1].num_pages;
	    spellbook_ar[c+1].num_pages = swap;
	 }
      
      }
   
   }
   for(int b=0; b<num_spellbook; b++){
      cout << spellbook_ar[b].title << " " << spellbook_ar[b].num_pages << endl;;
   }

}

/****************************************************************
 * Function:sort_spell_effect
 * Description:this is used to sort spell by their effect
 * Parameters:s, num_spells, spellbook_ar, num_spellbook, isStudent
 * Pre-conditions:the choose function is created
 * Post-conditions:user is allowed to pick another option
 ****************************************************************/
void sort_spell_effect(spell *s, int num_spells, spellbook *spellbook_ar, int num_spellbook, bool isStudent){
   for (int k =0; k < 5; k++){
      for(int i =0; i<num_spellbook; i++){
	 for(int j=0; j<spellbook_ar[i].num_spells; j++){
	    if(spellbook_ar[i].s[j].effect == "bubble" && k==0){
	       cout << spellbook_ar[i].s[j].effect<< " " << spellbook_ar[i].s[j].name << endl;
	    }
	    else if(spellbook_ar[i].s[j].effect == "memory_loss" && k==1){
	       cout << spellbook_ar[i].s[j].effect<< " " << spellbook_ar[i].s[j].name << endl;
	    }
	    else if(spellbook_ar[i].s[j].effect == "fire" && k==2 ){
	       cout << spellbook_ar[i].s[j].effect<< " " << spellbook_ar[i].s[j].name << endl;
	    }
	    else if(spellbook_ar[i].s[j].effect == "poison" && k==3 && isStudent){
	       cout << spellbook_ar[i].s[j].effect<< " " << spellbook_ar[i].s[j].name << endl;
	    }
	    else if(spellbook_ar[i].s[j].effect == "death" && k==4 && isStudent){
	       cout << spellbook_ar[i].s[j].effect<< " " << spellbook_ar[i].s[j].name << endl;
	    }

	 }
      }
   }

}

/****************************************************************
 * Function:sort_success_rate
 * Description:this is used to sort the spells by the average success rate
 * Parameters:spellbook_ar, num_spellbook
 * Pre-conditions:the choose function is created
 * Post-conditions:the user is giving th option to try another operation or quit
 ****************************************************************/
void sort_success_rate(spellbook * spellbook_ar, int num_spellbook){
   for(int i=0; i<num_spellbook; i++){
      for(int c=0; c<num_spellbook-1; c++){
	 if(spellbook_ar[c].avg_success_rate > spellbook_ar[c+1].avg_success_rate){
	    int swap = spellbook_ar[c].avg_success_rate;
	    spellbook_ar[c].avg_success_rate = spellbook_ar[c+1].avg_success_rate;
	    spellbook_ar[c+1].avg_success_rate = swap;
	 }
      
      }
   
   }
   for(int b=0; b<num_spellbook; b++){
      cout << spellbook_ar[b].title << " " <<spellbook_ar[b].avg_success_rate << endl;;
   }

}

/****************************************************************
 * Function:delete_info
 * Description:this is used to delet arrays
 * Parameters:wiz_ar, spellbook_ar, num_spellbook
 * Pre-conditions:arrays are created on the heap
 * Post-conditions:none
 ****************************************************************/
void delete_info(wizard ** wiz_ar, spellbook** spellbook_ar,int num_spellbook){
   for(int i=0; i<num_spellbook; i++){
      delete[] (*spellbook_ar)[i].s;
   }
      delete[]*spellbook_ar;
      delete[]*wiz_ar;


}



