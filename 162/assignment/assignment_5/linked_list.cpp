#include"linked_list.h"
#include"list_node.h"
#include<iostream>

using namespace std;

/*****************************************************************
 * Function:Linked_List()
 * Description:This is a constructor and it sets the conitions for the members of the class
 * Parameters:none
 * Pre-conditions:class is created
 * Post-conditions:other functions can be set
 *****************************************************************/
Linked_List::Linked_List(){
   first = NULL;
   length=0;
}

/*****************************************************************
 * Function:get_length()
 * Description:returns the length of the list
 * Parameters:none
 * Pre-conditions:length object is created
 * Post-conditions:the program can move on
 *****************************************************************/
int Linked_List::get_length(){
   return length;
}

/*****************************************************************
 * Function:push_back(int value)
 * Description:adds a new number at the end of the list
 * Parameters:value
 * Pre-conditions:node class is created
 * Post-conditions:the list can be created
 *****************************************************************/
unsigned int Linked_List::push_back(int value){
   Linked_List_Node *temp =first;
   if(first==NULL){
      temp= new Linked_List_Node;
      temp->val=value;
      temp->next=NULL;
      first = temp;
   }
   else{

   while(temp->next!=NULL){
      temp=temp->next;
}
   temp->next= new Linked_List_Node;
   temp->next->val=value;
   temp->next->next=NULL;
   }
   return ++length;
}

/*****************************************************************
 * Function:push_front(int value)
 * Description:puts number at the fron of the link
 * Parameters:value
 * Pre-conditions:class is created
 * Post-conditions:you can print the list after
 *****************************************************************/
unsigned int Linked_List::push_front(int value){
   return insert(value,0);
}

/*****************************************************************
 * Function:insert(value, index)
 * Description:it allows the user put a number anywhere on the list
 * Parameters:value, index
 * Pre-conditions:class has been created 
 * Post-conditions:the list can be printed
 *****************************************************************/
unsigned int Linked_List::insert(int value, unsigned int index){
   Linked_List_Node *temp = first;
   for(int i=0; i<index; i++){
      temp=temp->next;
   }
   Linked_List_Node *temp2 = temp->next;
   Linked_List_Node *new_node = new Linked_List_Node;
   new_node->val = value;
   temp->next=new_node;
   new_node->next=temp2;
   return ++length;
}

/*****************************************************************
 * Function:isPrime(int value)
 * Description:this gets the amount of prime numbers from the list
 * Parameters:value
 * Pre-conditions:the lis has been gotten from the user
 * Post-conditions:the amount of prime numbers is printed
 *****************************************************************
bool Linked_List::isPrime(){
   int count=0;
   Linked_List_Node *temp =first;
   if(val == 0){
      return true;
   }
   else{
      for (int x =2; x <= input/2; x++){
	 if (input % x ==0)
	    count++;
		}
	}
}*/

/*****************************************************************
 * Function:print()
 * Description:this print the list of numbers
 * Parameters:none
 * Pre-conditions:the numbers have been added to the list
 * Post-conditions:the linked list can be cleared
 *****************************************************************/
void Linked_List::print(){
   Linked_List_Node *temp=first;
   for(int i=0; i<length; i++){
      cout << temp->val << endl;
      temp=temp->next;

   }   
}

/*****************************************************************
 * Function:clear()
 * Description:this is used to clear all the linked list and free up memory
 * Parameters:none
 * Pre-conditions:the list has been printed
 * Post-conditions:the program ends
 *****************************************************************/
void Linked_List::clear(){
   Linked_List_Node *temp =first;
   for(int i=0; i<length; i++){
      temp=first;
      first= temp->next;
      delete temp;
}
}
