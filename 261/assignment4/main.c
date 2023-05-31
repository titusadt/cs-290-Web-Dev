#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include "avl.h"



void preorder(struct AVLnode *node, TYPE *min_cost, TYPE *path, int *i, TYPE *stat_path, int *j, TYPE sumDiff,  TYPE parent_value);
TYPE absolutediff(TYPE a, TYPE b);
int FindMinPath(struct AVLTree *tree, TYPE *path);
void printBreadthFirstTree(struct AVLTree *tree);


/* -----------------------
The main function
  param: argv = pointer to the name (and path) of a file that the program reads for adding elements to the AVL tree
*/
int main(int argc, char** argv) {
	FILE *file;
	int len, i;
	TYPE num; /* value to add to the tree from a file */
	struct timeval stop, start; /* variables for measuring execution time */
	int pathArray[50];  /* static array with values of nodes along the min-cost path of the AVL tree -- as can be seen, the tree cannot have the depth greater than 50 which is fairly sufficient for out purposes*/

	struct AVLTree *tree;
	
/*printf("%s", "Error");	*/
	tree = newAVLTree(); /*initialize and return an empty tree */
	/*printf("What is argv %s", argv[1]);*/	
	file = fopen(argv[1], "r"); 	/* filename is passed in argv[1] */
	assert(file != 0);

	/* Read input file and add numbers to the AVL tree */
	while((fscanf(file, "%i", &num)) != EOF){
		addAVLTree(tree, num);		
	}
	/* Close the file  */
	fclose(file);
	
	printf("\nPrinting the tree breadth-first : \n");
	printBreadthFirstTree(tree);

	gettimeofday(&start, NULL);
	/* Find the minimum-cost path in the AVL tree*/
	len = FindMinPath(tree, pathArray);
	
	gettimeofday(&stop, NULL);

	/* Print out all numbers on the minimum-cost path */
	printf("\nThe minimum-cost path is: \n");
	for(i = 0; i < len; i++)
		printf("%d ", pathArray[i]);
	printf("\n");

	printf("\nYour execution time to find the mincost path is %f microseconds\n", (double) (stop.tv_usec - start.tv_usec));

        /* Free memory allocated to the tree */
	deleteAVLTree(tree); 
	
	return 0;
}


  
/* --------------------
Finds the minimum-cost path in an AVL tree
   Input arguments: 
        tree = pointer to the tree,
        path = pointer to array that stores values of nodes along the min-cost path, 
   Output: return the min-cost path length 

   pre: assume that
       path is already allocated sufficient memory space 
       tree exists and is not NULL
*/
int FindMinPath(struct AVLTree *tree, TYPE *path)
{
               /* FIX ME */
   int path_length = 0;
   struct AVLnode *curr = tree->root;
   TYPE min_cost = (TYPE) 10^6 * tree->cnt;
   int stat_path_length = 0;
   TYPE stat_path[1000];

   path[path_length] = tree->root->val;
   path_length++;

   if(tree->cnt >1){
      preorder(curr, &min_cost, path, &path_length, stat_path, &stat_path_length, 0, curr->val);
   }
   return path_length;
	
}

TYPE absolutediff(TYPE a, TYPE b){
   if(a<0){
      return (TYPE) 0;
   }
   else{
      return (TYPE) abs(a-b);
   }
}

void preorder(struct AVLnode *node, TYPE *min_cost, TYPE *path, int *path_length, TYPE *stat_path, int *stat_path_length,            TYPE sumDiff,  TYPE parent_value){
   int i;
   
   stat_path[*stat_path_length] = node->val;
   (*stat_path_length)++;

   sumDiff = sumDiff + absolutediff(parent_value, node->val);

   if(sumDiff >= *min_cost){
      (*stat_path_length)--;
      return;
   }

   if(!node->left && !node->right){
      if(sumDiff < *min_cost){
         *min_cost = sumDiff;
	 for(i=0; i < *stat_path_length; i++){
	    path[i] = stat_path[i];
	 }
	 *path_length = *stat_path_length;
	 (*stat_path_length)--;
      }
   }
   
      else{
         if(node->left){ 
	    preorder(node->left, min_cost, path, path_length, stat_path, stat_path_length, sumDiff, node->val);
	 }
         if(node->right){
	    preorder(node->right, min_cost, path, path_length, stat_path, stat_path_length, sumDiff, node->val);
	 }
	 (*stat_path_length)--;
      }
}


/* -----------------------
Printing the contents of an AVL tree in breadth-first fashion
  param: pointer to a tree
  pre: assume that tree was initialized well before calling this function
*/
void printBreadthFirstTree(struct AVLTree *tree)
{
   
    /* FIX ME */
   struct AVLnode **queue;
   struct AVLnode *current = tree->root;
   int start=0;
   int finish=0;
   int i;
   
   queue = (struct AVLnode **)malloc(100*sizeof(struct AVLnode));
   
   queue[finish]=current;
   finish++;

   while(start < finish){
      current = queue[start];
      start++;

      if(current->left){
         queue[finish] = current->left;
         finish++;
   }
      if(current->right){
         queue[finish] = current->right;
         finish++;
   }
}
   for(i=0; i<finish; i++){ 
      printf("%d ", queue[i]->val);
   }
   printf("\n");
   
   free(queue);
  
}



