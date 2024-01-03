# TYPE WRAPPER #
TypeWrapper is a structure template, which gets its inspiration from Wrapper Classes in Java. In this header file, I have already defined the Wrappers for int, float, double, char, c-string namely: Integer, Float, Double, Character, String respectively.
## The TypeWrapper Structure ##
```C
typedef struct TypeWrapper
{
	void *data;
	void (*print)(struct TypeWrapper);
	void (*copy)(struct TypeWrapper, struct TypeWrapper);
	int (*compare)(struct TypeWrapper, struct TypeWrapper);
	char *type_string;
}TypeWrapper;
```
## Available Wrappers ##
1. Integer
2. Float
3. Double
4. Character
5. String
## Functions ##
1. ```Integer newInteger(int data)```: Used to create a new Integer.
2. ```Float newFloat(float data)```: Used to create a new Float.
3. ```Double newDouble(double data)```: Used to create a new Double.
4. ```Character newCharacter(char data)```: Used to create a new Character.
5. ```String newString(const char* data)```: Used to create a new String.
## Utility Functions ##
1. ```int Integer2int(Integer obj)```: Converts an Integer Wrapper to primitive int type.
2. ```float Float2float(Float obj)```: Converts an Float Wrapper to primitive float type.
3. ```double Double2double(Double obj)```: Converts an Double Wrapper to primitive double type.
4. ```char Character2char(Character obj)```: Converts an Character Wrapper to primitive char type.
5. ```char* String2str(String obj)```: Converts an String Wrapper to C-String type.
## Creating Your Own TypeWrapper ##
1. ```typedef TypeWrapper <wrapper_name>```
2. Create ```print(), copy() & compare()``` functions
3. Create  ```new<Wrapper>()``` function
### Example ###
Suppose, you want to define the Integer Wrapper. It will look like this:
```C
typedef TypeWrapper Integer;
void printInteger(Integer obj)
{
	if(strcmp(type(obj),"Integer")==0)
	{
		if(obj.data) printf("%d",*(int*)obj.data);
		else printf("NIL");
	}
	else
		printf("Not an Integer!\n");
}
void cpyInteger(Integer dest, Integer src)
{
	if(strcmp(type(dest),"Integer")==0&&strcmp(type(src),"Integer")==0)
		*(int*)dest.data = *(int*)src.data;
	else
		printf("Incompatible Types!\n");
}
int cmpInteger(Integer obj, Integer obj2)
{
	if(strcmp(type(obj),"Integer")==0&&strcmp(type(obj2),"Integer")==0)
		return (*(int*)obj.data > *(int*)obj2.data)? 1: (*(int*)obj.data < *(int*)obj2.data)? -1:0;
	else
	{
		printf("Incompatible Types!\n");
		return INT_MIN;
	}
}
Integer newInteger(int data)
{
	Integer* obj = (Integer *) malloc(sizeof(Integer));
	obj->data = malloc(sizeof(void*));
	*(int*)obj->data = data;
	obj->print = printInteger;
	obj->copy  = cpyInteger;
	obj->compare = cmpInteger;
	obj->type_string = (char *) malloc(sizeof("Integer"));
	strcpy(obj->type_string, "Integer");
	return *obj;
}
```
