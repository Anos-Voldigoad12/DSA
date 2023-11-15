# Iterator #
Iterators in C is similar to Iterators in Python with JS functions like forEach(), find() and reduce().

## The Iterator Structure ##
```C
typedef struct iter_node
{
	void *data;
	struct iter_node *prev, *next;
}iter_node;
typedef struct
{
	iter_node* start;
	iter_node* cur;
	iter_node* end;
}iterator;
```
## Functions ##
1. ```iterator* newIterator()```: Creates a new iterator
2. ```void addIter(iterator* iter, void *data)```: Adds a new node to the iterator
3. ```void removeIterFront(iterator* iter)```: Removes a node from the front of the iterator
4. ```void removeIterRear(iterator* iter)```: Removes a node from the rear of the iterator
5. ```int hasNextIter(iterator* iter)```: Checks if the iterator has a next node
6. ```void* nextIter(iterator* iter)```: Returns the data of the current node, and moves to the next node
7. ```void* prevIter(iterator* iter)```: Returns the data of the current node, and moves to the prev node
8. ```void* peekIter(iterator* iter)```: Returns the data of the current node

9. ```void forEachIter(iterator* iter, void (*fn)(void *))```: Applies a void function fn(void *) on each data on the iterator 
10. ```iter_node* findIter(iterator* iter, void* ref, int (* cmp)(void *, void *))```: Finds the node which causes the function: void cmp(void * data, void *ref) to be true
11. ```void reduceIter(iterator* iter, void* result, void (* op)(void*, void*))```: Applies the function void op(void* result, void *data) on each data on the iterator  
12. ```void reverseIter(iterator *iter)```: Reverses the iterator
