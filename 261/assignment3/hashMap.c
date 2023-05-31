#include <stdlib.h>
#include "hashMap.h"
#include "structs.h"
#include <string.h>
#include<assert.h>

#define MAX_LOAD_FACTOR 2.0

int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}

int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*the difference between 1 and 2 is on this line*/
	return r;
}

void initMap (struct hashMap * ht, int tableSize)
{
	int index;
	if(ht == NULL)
		return;
	ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
	ht->tableSize = tableSize;
	ht->count = 0;
	for(index = 0; index < tableSize; index++)
		ht->table[index] = NULL;
}

void freeMap (struct hashMap * ht)
{  /*write this*/
   int i;
   struct hashLink* temp;
   struct hashLink* temp2;

   for(i=0; i<ht->tableSize; i++){
      temp = ht->table[i];
      while(temp!=NULL){
         temp2 = temp->next;
	 free(temp->key);
	 free(temp);
	 temp=temp2;
      }
   
   }

   free(ht->table);
   ht->count =0;
   ht->table=0;
   ht->tableSize=0;
}

void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{  /*write this*/
   int hash;
   int hashindex = (ValueType)(labs(hash)%ht->tableSize);
   struct hashLink *newLink = (struct hashLink*)malloc(sizeof(struct hashLink));

   assert(ht && k);

   if(EQ(HASHING_FUNCTION, 1)){
      hash = stringHash1(k);
   }
   else{
      hash = stringHash2(k);
   }

   /*if(!containsKey){*/
      assert(newLink);
      newLink->key = (KeyType)malloc(sizeof(char)*(strlen(k)+1));
      assert(newLink->key);
      strcpy(newLink->key, k);

      newLink->value = v;
      newLink->next = ht->table[hashindex];
      ht->table[hashindex] = newLink;
      ht->count++;
     
   

}

ValueType* atMap (struct hashMap * ht, KeyType k)
{
   int hash;
   hashLink *curr;
   int hashindex = (ValueType)(labs(hash)%ht->tableSize);
   if(EQ(HASHING_FUNCTION, 1)){
      hash = stringHash1(k);
   }
   else{
      hash = stringHash2(k);
   }
   
   if(containsKey){   
      curr=ht->table[hashindex];
      while(curr!=0){
         if(curr->key == k){
	   return &curr->value;
	 }
      }
   }
   else{
      return NULL;
   }
}   



int containsKey (struct hashMap * ht, KeyType k)
{  /*write this*/
   if(atMap(ht, k)==0){
      return 0;
   }
   else{
      return 1;
   }
}

void removeKey (struct hashMap * ht, KeyType k)
{  /*write this?*/
   int hash = stringHash1(k);
   int hashindex = (int)(labs(hash)%ht->tableSize);
   hashLink *curr, *last;
   /*assert(!isEmptyHashTable);*/
   if(containsKey(ht, k)){
      curr = ht->table[hashindex];
      last = ht->table[hashindex];

      while(curr!=0){
         if(curr->key == k){
	    if(curr == ht->table[hashindex])
	       ht->table[hashindex] = curr->next;
	    else last->next = curr->next;
	    free(curr);
	    curr = 0;
	 }

	 else{
	    last = curr;
	    curr = curr->next;
	 }
      }
   }
}

int sizeMap (struct hashMap *ht)
{  /*write this*/
   return ht->count;
}

int capacityMap(struct hashMap *ht)
{  /*write this*/
   return ht->tableSize;
}

int emptyBuckets(struct hashMap *ht)
{  /*write this*/
   int empty =0;
   int i;
   for(i=0; i<ht->tableSize; i++){
      if(ht->table[i] == 0){
         empty++;
      }
   }
   return empty;
}

float tableLoad(struct hashMap *ht)
{  /*write this*/
   return(float)sizeMap(ht) / (float)capacityMap(ht);
}
