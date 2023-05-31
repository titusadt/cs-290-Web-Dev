#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int get_size(){
   int size;
   cout << "Enter the length of your array: " ;
   cin >> size;
   return size;
}

int check_size(int size){
   if(size >= 0 && size<20){
      return size;
   }
   else{
      cout << "Invalid input" << endl;
      exit(0);
   }
}

  

void copyArray(int A[], int iBegin, int iEnd, int B[]){
   for(int i=iBegin; i<iEnd; i++){
      A[i]=B[i];
   }   

}

int main(){
   srand(time(NULL));
   int size;
   size = get_size();
   check_size(size);
   int *new_ar = new int[size];
   check_size(size);
   for(int i=0; i<size; i++){
      new_ar[i] = rand()%50+1;
      cout << new_ar[i] << endl;
   }


return 0;
}
