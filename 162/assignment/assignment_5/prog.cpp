/******************************************************************
 * Program:Linked_List
 * Author:Temi
 * Date:6/9/2019
 * Description:I will take numbers from the user and store it in a linked list, then I will sort them in ascending or descending        order and display the amount of prime numbers in the list
 * Input:numbers from the user
 * Output:the list and the prime numbers
 *****************************************************************/
#include<iostream>
#include"linked_list.h"

using namespace std;

int main(){
  int num;
  string ans, pick;
  Linked_List list;
  cout << "Please enter a number: " ;
  cin >> num;
  list.push_back(num);
  cout << "Do you want to enter another number(y, n): ";
  cin >> ans;
  while(ans == "y"){
     cout << "Enter a number: ";
     cin >> num;
     list.push_back(num);
     cout << "Do you want to enter another number(y, n): ";
     cin >> ans;
     }
  list.print();
  list.clear();

  


return 0;
}
