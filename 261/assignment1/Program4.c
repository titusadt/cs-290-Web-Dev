/* CS261- HW1 - Program4.c*/
/* Name: Teminijesu Titus Adewunmi
 * Date: 1/21/2020
 * Solution description: this program sorts the random initals created in program 2 into ascending order and prints out the result
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct student{
	char initials[2];
	int score;
};

void sort(struct student* students, int n){
   /*Sort n students based on their initials*/     
   int temp;
   int i, j;
   for(i=0; i<n; i++){
      for(j=0; j<n-1; j++){
         if(students[j].initials[0] > students[j+1].initials[0]){
	    temp = students[j].initials[0];
	    students[j].initials[0] = students[j+1].initials[0];
	    students[j+1].initials[0] = temp;
	 }
	 else if(students[j].initials[0] == students[j+1].initials[0]){
	    temp = students[j].initials[1];
	    students[j].initials[1] = students[j+1].initials[1];
	    students[j+1].initials[1] = temp;
	 }
      } 
   }
}


int main(){
    srand(time(NULL));
    /*Declare an integer n and assign it a value.*/
    int n = 10;    
    /*Allocate memory for n students using malloc.*/
    struct student* students = (struct student*)malloc(sizeof(struct student));
    /*Generate random IDs and scores for the n students, using rand().*/
    int i;
    for(i=0; i<n; i++){
       char c1 = rand()%26 + 'A';
       char c2 = rand()%26 + 'A';
       int scores = rand()%101;
       students[i].initials[0] = c1;
       students[i].initials[1] = c2;
       students[i].score = scores;
    }
    /*Print the contents of the array of n students.*/
    int c;
    for(c=0; c<n; c++){
       printf("%d. ", c+1);
       printf("%c", students[c].initials[0]);
       printf("%c ", students[c].initials[1]);
       printf("%d \n", students[c].score);
    
    }
    /*Pass this array along with n to the sort() function*/
    sort(students, n);    
    /*Print the contents of the array of n students.*/
    int j;
    printf("Sorted List: \n");
    for(j=0; j<n; j++){
       printf("%d. ", j+1);
       printf("%c", students[j].initials[0]);
       printf("%c ", students[j].initials[1]);
       printf("%d \n", students[j].score);
    
    }
    return 0;
}
