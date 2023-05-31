
void removeMinPriorityHeap(struct Dynarr *heap){
   assert(heap&&heap->size >0);
/*this will be done by copying the lowest priority value to the heap
 * decrease the heap size by 1
 * then percolate down the tree
 * if the current node has no children then it is done 
 * if it has children check if it is one or twon then make the appropriate swaps */
   if(heap->size){
      heap->data[0] = heap->data[heap->size];
   }
   if(rightidx >=heapsize){
      if(leftidx >= heap->size)
	 return;
   
      else{
         minIndex(heap, leftidx, rightidx) = leftindex;
      }
   }
   else{
     if (data[leftidx] < data[rigthidx])
	
         minIndex(heap, leftidx, rightidx) = leftindex;
     else{
         minIndex(heap, leftidx, rightidx) = rightindex;
      }
   }
   swap(heap, leftchild, rightchild);
   heap->size --;


}
