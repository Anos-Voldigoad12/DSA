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
1. ```map* newMap(int (*genKey)(void*), int (*cmp)(void*, void*), void (*cpyKey)(void*, void*), void (*cpyData)(void*, void*))```: Used to create a new Map
2. ```void putItem(map* m, void* key, void* data)```: Used to put a new Key-Value pair into the Map
3. ```void* getVal(map* m , void* key)```: Get the value corresponding to a given Key in the Map
4. ```void** getKeys(map *m)```: Returns an array of Keys of the type void *
5. ```void** getVals(map *m)```: Returns an array of Values of the type void *
6. ```void removeItem(map* m , void* key)```: Remove the item having the given Key
7. ```int containsKey(map* m, void* key)```: Checks if a Key is present in the Map
8. ```void _cleanMap(map *m)```: Destroy unused Map Blocks
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
