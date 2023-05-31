/************************************************************
 * Program Filename:zoo_tycoon
 * Author:Temi
 * Date:5/12/19
 * Decription:this is a game where a player takes care of animals and gets revenue
 * Input:all the necessary commands to play the game
 * Output:all the necessary commands to play the game
 ***********************************************************/
#include<iostream>
#include<string>
#include "animal.h"
#include"monkey.h"
#include"zoo.h"

using namespace std;

int main(){
 int ans;
 Animal a;
 Zoo z;
 do{
 cout << "Welcome to Zoo Tycoon!" << endl;
 a.add_age();
 z.purchase_animal();
 z.buy_feed();
 z.special_event();
 z.add_revenue();
 z.check_bank();
 cout << "Do you want to keep playing?(yes-1, no -2)" << endl;
 cin >> ans;
 }while(ans==1);
return 0;
}
