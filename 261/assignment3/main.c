#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hashMap.h"

/*
 the getWord function takes a FILE pointer and returns you a string which was
 the next word in the in the file. words are defined (by this function) to be
 characters or numbers separated by periods, spaces, or newlines.
 
 when there are no more words in the input file this function will return NULL.
 
 this function will malloc some memory for the char* it returns. it is your job
 to free this memory when you no longer need it.
 */
char* getWord(FILE *file); /* prototype */

/****************************************/

int main (int argc, const char * argv[]) {
    /*Write this function*/
   const char* filename;
   FILE *fptr;
   char * read_w;
   char * temp_w;
   int *val_k;
   struct hashMap h_table;
   struct hashLink *temp;
   int tableSize = 1000;
   int i;
    
   if(argc == 2){
      filename = argv[1];
   }
   else{
      filename = "input.txt";
      }

   printf("opening file: %s\n", filename);

   
   initMap(&h_table, tableSize);  
   fptr= fopen(filename, "r");
   assert(fptr);
    
   fptr= fopen(filename, "r");
   read_w = getWord(fptr);
   while(read_w){
      val_k = atMap(&h_table, read_w);
      if(val_k){
         (*val_k)++;
      }   
      else{
         insertMap(&h_table, read_w, 1);
      }
      
      temp_w = read_w;
      read_w = getWord(fptr);
      free(temp_w);
   }

   fclose(fptr);

   for(i=0; i<h_table.tableSize; i++){
      temp = h_table.table[i];
      while(temp!=0){
         printf("%s:%d\n", temp->key, temp->value);
	 temp = temp->next;
      }
   }

   freeMap(&h_table);

}


char* getWord(FILE *file)
{
	
	int length = 0;
	int maxLength = 16;
	char character;
    
	char* word = (char*)malloc(sizeof(char) * maxLength);
	assert(word != NULL);
    
	while( (character = fgetc(file)) != EOF)
	{
		if((length+1) > maxLength)
		{
			maxLength *= 2;
			word = (char*)realloc(word, maxLength);
		}
		if((character >= '0' && character <= '9') || /*is a number*/
		   (character >= 'A' && character <= 'Z') || /*or an uppercase letter*/
		   (character >= 'a' && character <= 'z') || /*or a lowercase letter*/
		   character == 39) /*or is an apostrophy*/
		{
			word[length] = character;
			length++;
		}
		else if(length > 0)
			break;
	}
    
	if(length == 0)
	{
		free(word);
		return NULL;
	}
	word[length] = '\0';
	return word;
}

