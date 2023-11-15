# Heterogeneous List #
Heterogeneous List (or HeterList) is a data structure that is inspired from Lists in Python. It is a list of heterogeneous data i.e., each node can have a diffent type of data.
Requires: [iter.h](https://github.com/Anos-Voldigoad12/DSA/blob/main/Data_Structures/Iterator/iter.h)
## The HeterList Structure ##
```C
typedef struct heter_node
{
	void* data;
	struct heter_node* next;
	struct heter_node* prev;
	void (*cpyData)(void *, void *);
	void (*printData)(void *);
}heter_node;
typedef struct HeterList
{
	heter_node* head;
	heter_node* tail;
	int size;
}HeterList;
```
## Functions ##
1. ```HeterList* newHeterList()```: Creates a new HeterList 
2. ```void addHeterNodeFront(HeterList* h, void* data, void (*cpyData)(void *, void *), void (*printData)(void *))```: Adds a new node at front
3. ```void addHeterNodeRear(HeterList* h, void* data, void (*cpyData)(void *, void *), void (*printData)(void *))```: Adds a new node at rear
4. ```void addHeterNode(HeterList* h, int index, void* data, void (*cpyData)(void *, void *), void (*printData)(void *))```: Appends a node at a specified index
5. ```void appendHeterList(HeterList* h, HeterList* h2)```: Appends a HeterList at the tail of another HeterList 
6. ```void removeHeterNodeFront(HeterList* h)```: Remove a node from the front
7. ```void removeHeterNodeRear(HeterList* h)```: Remove a node from the rear
8. ```void removeHeterNode(HeterList* h, int index)```: Remove a node from a specified index
9. ```void reverseHeterList(HeterList* h)```: Reverse a HeterList
10. ```heter_node* getNodeAtFront(HeterList* h, int index)```: Get the node at a specified index from front (starts from 0)
11. ```heter_node* getNodeAtRear(HeterList* h, int index)```: Get the node at a specified index from rear (starts from 1)
12. ```heter_node* getNodeAt(HeterList* h, int index)```: Get the node at a specidied index; negative index is allowed ** {PREFERRED} ** 
13. ```void printHeterList(HeterList* h)```: Prints the HeterList
14. ```iterator* heterList2Iter(HeterList* h)```: Converts the HeterList to an Iterator
## Utility Functions ##
1. For Integers:
   1. ```int genKeyFromInt(void *data)```: Generates a 0-9 key from Integer
   2. ```int isEqualInt(void *data, void *se)```: Checks if two Integers are equal
   3. ```void cpyInt(void *dest, void *src)```: Copies an Integer from one location to other
   4. ```void printInt(void *data)```: Prints an Integer
2. For Double:
   1. ```int genKeyFromDouble(void *data)```: Generates a 0-9 key from Double
   2. ```int isEqualDouble(void *data, void *se)```: Checks if two Doubles are equal
   3. ```void cpyDouble(void *dest, void *src)```: Copies a Double from one location to other
   4. ```void printDouble(void *data)```: Prints a Double
3. For Characters:
   1. ```int genKeyFromChar(void *data)```: Generates a 0-9 key from Character
   2. ```int isEqualChar(void *data, void *se)```: Checks if two Characters are equal
   3. ```void cpyChar(void *dest, void *src)```: Copies a Character from one location to other
   4. ```void printChar(void *data)```: Prints a Character
4. For Strings:
   1. ```int genKeyFromString(void *data)```: Generates a 0-9 key from String
   2. ```int isEqualString(void *data, void *se)```: Checks if two String are equal
   3. ```void cpyString(void *dest, void *src)```: Copies a String from one location to other
   4. ```void printString(void *data)```: Prints a String
