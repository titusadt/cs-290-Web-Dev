#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define TYPE int
#define EQ(a,b) (a == b)  

struct hlink{
   TYPE value;
   struct hlink *next;
}hashlink;

struct HashTable{
   struct hlink **table;
   int tablesize;
   int count;
}

void initHashTable(struct HashTable *ht, int size){
   int i;
   if(ht==NULL){
      return;
   } 
   ht->table = (hashlink *)malloc(sizeof(hashlink*)*size);
   assert(ht->table!=0);
   ht->tablesize =0;
   ht->count =0;
   for(i=0; i<size; i++){
      ht->table[i] =0;
   }
}

void _resizeTable(struct HashTable *ht){
   int i;
   int oldts = ht->tablesize;
   struct HashTable *oldht = ht;
   hlink *cur, *last;

  initHashTable(ht, 2*oldts);
 for(i=0; i<oldts; i++){
    cur = oldht[i]->table;
    while(cur !=0){
       addhashTable(ht, cur->value);
       last = cur;
       cur = cur->next;
       free(cur);
    }
 }
free(oldht); 

}



void addHashTable(struct hashTable *ht, TYPE newValue){
   int hash = HASH(newValue);
   hashIndex = (int)(labs(hash) % ht ->tablesize);

   struct hlink *newlink = (struct hlink*)malloc(sizeof(hlink));
   assert(newlink);

   newlink->value = newValue;
   newlink->next = ht->table[hashIndex];
   ht->table[hashIndex] = newlink;
   ht->count++;

   float 1f = ht->count/ht->tablesize;
   if(1f>8.0)
      _resizeTable(ht);
}

int containsHashTable(struct HashTable *ht, TYPE val){
   int hash = HASH(newValue);
   hashIndex = (int)(labs(hash) % ht->tablesize);
   hlink cur;

   cur = ht->table[hashIndex];

   while(cur!=0){
      if(cur->value == val)
	 return 1;
      cur = cur->next
   }
   return 0;


}

