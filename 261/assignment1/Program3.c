/* CS261- HW1 - Program3.c*/
/* Name: Teminijesu Titus Adewunmi
 * Date: 01/21/2020
 * Solution description: this progra, assigns 20 random numbers in an array and sorts them in ascending order.
 */
 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void sort(int* number, int n){
   /*Sort the array of integeres of length n*/
   int temp;
   int i, j;
   for(i=0; i<n; i++){
      for(j=0; j<n-1; j++){
         if(number[j] > number[j+1]){
	    temp = number[j];
	    number[j] = number[j+1];
	    number[j+1] = temp;
	 }    
      } 
   }
}

int main(){
    srand(time(NULL));
    int* number;
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
    if(number != NULL){
       number = (int*)malloc(sizeof(int));
    }
    else{
       printf("There is an error");
    }
    
    /*Fill this array with random numbers, using rand().*/
    int i;
    for(i=0; i<n; i++){
       number[i] = rand()%501;
    }
    
    /*Print the contents of the array.*/
    int c;
    printf("Contents of the array: \n");
    for(c=0; c<n; c++){
       printf(" %d \n", number[c]);
    }
    /*Pass this array along with n to the sort() function of part a.*/
    sort(number, n);    
    /*Print the contents of the array.*/    
    int j;
    printf("Sorted number \n");
    for(j=0; j<n; j++){
       printf("%d \n", number[j]); 
    }
    return 0;
}
