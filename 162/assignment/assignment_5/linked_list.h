#ifndef LINKED_LIST
#define LINKED_LIST
#include<iostream>
#include"list_node.h"
using namespace std;

class Linked_List{
   private:
      unsigned int length;
      Linked_List_Node *first;
   public:
      Linked_List();
      int get_length();
      void print();
      void clear();
      unsigned int push_front(int);
      unsigned int push_back(int);
      unsigned int insert(int val, unsigned int index);
      bool isPrime( );
      void sort_ascending();
      void sort_descending();      
};
#endif
