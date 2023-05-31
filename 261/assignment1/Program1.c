/* CS261- HW1 - Program1.c*/
/* Name: Teminijesu Titus Adewunmi
 * Date:1/21/2020
 * Solution description: This program is done by creting pointers, and assign variables to them. Then perfroming arithmetic operations
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c){
    /* Increment a */
    ++*a;
    /* Decrement  b */
    --*b;
    /* Assign a-b to c */
    c = *a-*b;
    /* Return c */
    return c;
}

int main(){
    /* Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    srand(time(NULL));
    int x = rand()%11;
    int y = rand()%11;
    int z = rand()%11;
    /* Print the values of x, y and z */
    printf("x is: %d \n", x);
    printf("y is: %d \n", y);
    printf("z is: %d \n", z);
    /* Call foo() appropriately, passing x,y,z as parameters */
    foo(&x, &y, z);
    /* Print the values of x, y and z */
    printf("\n");
    printf("x is: %d \n", x);
    printf("y is: %d \n", y);
    printf("z is: %d \n", z);

    /* Print the value returned by foo */
    printf("c is: %d \n", foo(&x, &y, z));

    /* Is the return value different than the value of z?  Why? */
    /*Yes the return value is different because it is a subtraction of normal numbers and not pointers*/
    return 0;
}


