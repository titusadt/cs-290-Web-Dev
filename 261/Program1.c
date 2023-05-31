#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void preorder(Node *node){
   if(node!=NULL){
      return;
   }
   printf("%d", node ->data);
   preorder(node->left);
   preorder(node->right);

}

void bst2avl(struct Tree *tree){
   assert(tree);
  
   current = tree->root;
   struct Node *newNode = (struct *)malloc(sizeof(struct *)) ;
   /* in order to convert a binary tree to an avl tree (balanced tree) i think it would just be any of the traversals in order to make        the bst balanced*/
   if(current != NULL){
      return;
   }
   Node *root = newNode;
   root->left = newNode;
   root->left->right = newNode
   preorder(root);
   return 0;
}
