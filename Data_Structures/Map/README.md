# Map #
Maps in C are similar to that in Java.

## The Map Structure ##
```C
typedef struct map_node
{
	void* key;
	void* data;
}map_node;
typedef struct map_block
{
	map_node block[10];
	struct map_block* next; 
}map_block;
typedef struct map
{
	map_block* first;
	int size;
	int (*genKey)(void*);
	int (*cmp)(void *, void *);
	void (*cpyKey)(void *, void *);
	void (*cpyData)(void *, void *);
}map;
```
## Functions ##
1. ```Cmap* newMap(int (*genKey)(void*), int (*cmp)(void*, void*), void (*cpyKey)(void*, void*), void (*cpyData)(void*, void*))```: Used to create a new Map
2. ```C void addItem(map* m, void* key, void* data)```: Used to add a new Key-Value pair to the Map
3. ```C void* getVal(map* m , void* key)```: Get the value corresponding to a given Key in the Map
4. ```C void** getKeys(map *m)```: Returns an array of Keys of the type void *
5. ```C void** getVals(map *m)```: Returns an array of Values of the type void *
6. ```C void removeItem(map* m , void* key)```: Remove the item having the given Key
7. ```C void _cleanMap(map *m)```: Destroy unused Map Blocks
## Utility Functions ##
1. For Integers:
   1. ```C int genKeyFromInt(void *data)```: Generates a 0-9 key from Integer
   2. ```C int isEqualInt(void *data, void *se)```: Checks if two Integers are equal
   3. ```C void cpyInt(void *dest, void *src)```: Copies an Integer from one location to other
   4. ```C void printInt(void *data)```: Prints an Integer
2. For Double:
   1. ```C int genKeyFromDouble(void *data)```: Generates a 0-9 key from Double
   2. ```C int isEqualDouble(void *data, void *se)```: Checks if two Doubles are equal
   3. ```C void cpyDouble(void *dest, void *src)```: Copies a Double from one location to other
   4. ```C void printDouble(void *data)```: Prints a Double
3. For Characters:
   1. ```C int genKeyFromChar(void *data)```: Generates a 0-9 key from Character
   2. ```C int isEqualChar(void *data, void *se)```: Checks if two Characters are equal
   3. ```C void cpyChar(void *dest, void *src)```: Copies a Character from one location to other
   4. ```C void printChar(void *data)```: Prints a Character
4. For Strings:
   1. ```C int genKeyFromString(void *data)```: Generates a 0-9 key from String
   2. ```C int isEqualString(void *data, void *se)```: Checks if two String are equal
   3. ```C void cpyString(void *dest, void *src)```: Copies a String from one location to other
   4. ```C void printString(void *data)```: Prints a String
