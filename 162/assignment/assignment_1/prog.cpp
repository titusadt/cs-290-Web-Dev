/*****************************************************************
 * Program filename: prog.cpp
 * Author:Temi
 * Date: 4/16/19
 * Description: I opened both of the files in this, created a wizard array and assigned he members of the struct in it and i called     my functions.
 * Input: Nothing.
 * Output: It shows that the file is able to open.
 ******************************************************************/
#include<iostream>
#include<fstream>
#include<string>
#include "wizard.h"

using namespace std;

int main(int argc, char *argv[]){
   int num_wizards, num_spellbook,b, num_spells;
   struct wizard* wiz_ar; //new struct wizard[100];
   struct spellbook* spellbook_ar;
   struct spell *s;
   string pass;

   if(argc != 3){
      cout << "There is a problem" << endl;
      return 1;
   }

  //opening the wizards.txt file 
   string wizard_filename = argv[1];
   ifstream ifs;
   ifs.open(wizard_filename.c_str(), ifstream::in);
   if(ifs.is_open()){
      cout << "The file is now open" << endl;
      ifs >> num_wizards;
      wiz_ar = new struct wizard[num_wizards];
      for(int i=0; i<num_wizards; i++){
         ifs >> wiz_ar[i].name;
	 ifs >> wiz_ar[i].id;
	 ifs >> wiz_ar[i].password;
	 ifs >> wiz_ar[i].position_title;
	 ifs >> wiz_ar[i].beard_length;
      }

   }
   else{
      cout << "Error opening wizard file" << endl;
   }

   //opening the spellbooks.txt file
   string spellbook_filename = argv[2];
   ifstream ifs2;
   ifs2.open(spellbook_filename.c_str(), ifstream::in);
   if(ifs2.is_open()){
      ifs2 >>num_spellbook;
      cout << "The file is now open" << endl;
   }
   else{
      cout << "Error opening spellbook file" << endl;
    
   }
   int get = get_id(&pass);
   bool isStudent = check_id(wiz_ar, get , num_wizards, &pass);
   spellbook_ar = create_spellbook(num_spellbook);
   cout << num_spellbook << endl;
   get_spellbook_data(spellbook_ar, num_spellbook, ifs2);
   cout << spellbook_ar[0].s[0].effect << endl;
   choose(spellbook_ar, num_spellbook, s, num_spells, isStudent);
   delete_info(&wiz_ar, &spellbook_ar,num_spellbook);



return 0;
}
