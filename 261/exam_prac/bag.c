/* Bag Implementation */
void initBag (struct arrayBagStack * b){
/* Insert your code */
   b->count = 0;
}
void addBag (struct arrayBagStack * b, TYPE v) {
/* Insert your code */
   b->data[b->count] = v;
   b->count++;
}
int containsBag (struct arrayBagStack * b, TYPE v){
/* Insert your code */
   int i;
   for(i=0; i< b->count; i++){
      if(EQ(b->data[i], v));
      return i;
   }
   return -1;
}
void removeBag (struct arrayBagStack * b, TYPE v) {
/* Insert your code */

}
int sizeBag (struct arrayBagStack * b) {
/* Insert your code */
}
/* Stack Implementation */
void pushStack (struct arrayBagStack * b, TYPE v) {
/* Insert your code */
}
TYPE topStack (struct arrayBagStack * b) {
/* Insert your code */
}
void popStack (struct arrayBagStack * b) {
/* Insert your code */
}
int isEmptyStack (struct arrayBagStack * b) {
/* Insert your code */
}
