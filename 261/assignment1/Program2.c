/* CS261- HW1 - Program2.c*/
/* Name: Teminijesu Titus-Adewunmi
 * Date: 01/21/2020
 * Solution description: this program assigns reandom initial and scores to 20 students and prints out the result then the minimum      the maximum and the average is calculated.
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


struct student{
	char initials[2];
	int score;
};

struct student* allocate(){
    /*Allocate memory for ten students*/
     struct student* student_arr = (struct student*)malloc(sizeof(struct student)*10);
     /*return the pointer*/
     return student_arr;
}

void generate(struct student* students){
     /*Generate random initials and scores for ten students.
	The two initial letters must be capital and must be between A and Z.
	The scores must be between 0 and 100*/
    int i;
    for(i=0; i<10; i++){
       char c1 = rand()%26 + 'A';
       char c2 = rand()%26 + 'A';
       int scores = rand()%101;
       students[i].initials[0] = c1;
       students[i].initials[1] = c2;
       students[i].score = scores;
    }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              1. Initials  Score
              2. Initials  Score
              ...
              10. Initials Score*/
    int c;
    for(c=0; c<10; c++){
       printf("%d. ", c+1);
       printf("%c", students[c].initials[0]);
       printf("%c ", students[c].initials[1]);
       printf("%d \n", students[c].score);

    }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int count_min = students[0].score;
    int i, c, b;
    for(i=0; i<10; i++){
      if(students[i].score < count_min){
         count_min = students[i].score;
      }
    }
    printf("The Minimum is: %d \n", count_min);

    int count_max = students[0].score;
    for(c=0; c<10; c++){
      if(students[c].score > count_max){
         count_max = students[c].score;
      }
    }
    printf("The Maximum is: %d \n", count_max);

    int total = 0;
    for(b=0; b<10; b++){
       total  += students[b].score;
    }
    int average = total/10;
    printf("The average is: %d \n", average);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     stud = (struct student*) realloc(stud, sizeof(struct student)*10);
}

int main(){
    srand(time(NULL));
    struct student* stud = allocate();

    /*call allocate*/
    /*call generate*/
    generate(stud);
    /*call output*/
    output(stud);
    /*call summary*/
    summary(stud);
    /*call deallocate*/
    deallocate(stud);
    return 0;
}
