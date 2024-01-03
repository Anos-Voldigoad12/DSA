#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define TYPE_WRAPPER 1

typedef struct TypeWrapper
{
	void *data;
	void (*print)(struct TypeWrapper);
	void (*copy)(struct TypeWrapper, struct TypeWrapper);
	int (*compare)(struct TypeWrapper, struct TypeWrapper);
	char *type_string;
}TypeWrapper;
char* type(TypeWrapper t)
{
	return t.type_string;
}
//Defined Wrappers
typedef TypeWrapper Integer, Character, Float, Double, String;

//Wrapper Creation Methods
Integer newInteger(int data);
Float newFloat(float data);
Double newDouble(double data);
Character newCharacter(char data);
String newString(const char* data);

//For Integer Wrapper
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

//For Float Wrapper
void printFloat(Float obj)
{
	if(strcmp(type(obj),"Float")==0)
	{
		if(obj.data) printf("%.3f",*(float*)obj.data);
		else printf("NIL");
	}
	else
		printf("Not a Float!\n");
}
void cpyFloat(Float dest, Float src)
{
	if(strcmp(type(dest),"Float")==0&&strcmp(type(src),"Float")==0)
		*(float*)dest.data = *(float*)src.data;
	else
		printf("Incompatible Types!\n");
}
int cmpFloat(Float obj, Float obj2)
{
	if(strcmp(type(obj),"Float")==0&&strcmp(type(obj2),"Float")==0)
		return (*(float*)obj.data > *(float*)obj2.data)? 1: (*(float*)obj.data < *(float*)obj2.data)? -1:0;
	else
	{
		printf("Incompatible Types!\n");
		return INT_MIN;
	}
}
Float newFloat(float data)
{
	Float* obj = (Float *) malloc(sizeof(Float));
	obj->data = malloc(sizeof(void*));
	*(float*)obj->data = data;
	obj->print = printFloat;
	obj->copy  = cpyFloat;
	obj->compare = cmpFloat;
	obj->type_string = (char *) malloc(sizeof("Float"));
	strcpy(obj->type_string, "Float");
	return *obj;
}

//For Double Wrapper
void printDouble(Double obj)
{
	if(strcmp(type(obj),"Double")==0)
	{
		if(obj.data) printf("%.5f",*(double*)obj.data);
		else printf("NIL");
	}
	else
		printf("Not a Double!\n");
}
void cpyDouble(Double dest, Double src)
{
	if(strcmp(type(dest),"Double")==0&&strcmp(type(src),"Double")==0)
		*(double*)dest.data = *(double*)src.data;
	else
		printf("Incompatible Types!\n");
}
int cmpDouble(Double obj, Double obj2)
{
	if(strcmp(type(obj),"Double")==0&&strcmp(type(obj2),"Double")==0)
		return (*(double*)obj.data > *(double*)obj2.data)? 1: (*(double*)obj.data < *(double*)obj2.data)? -1:0;
	else
	{
		printf("Incompatible Types!\n");
		return INT_MIN;
	}
}
Double newDouble(double data)
{
	Double* obj = (Double *) malloc(sizeof(Double));
	obj->data = malloc(sizeof(void*));
	*(double*)obj->data = data;
	obj->print = printDouble;
	obj->copy  = cpyDouble;
	obj->compare = cmpDouble;
	obj->type_string = (char *) malloc(sizeof("Double"));
	strcpy(obj->type_string, "Double");
	return *obj;
}

//For Character Wrapper
void printCharacter(Character obj)
{
	if(strcmp(type(obj),"Character")==0)
	{
		if(obj.data) printf("\'%c\'",*(char*)obj.data);
		else printf("NIL");
	}
	else
		printf("Not a Character!\n");
}
void cpyCharacter(Character dest, Character src)
{
	if(strcmp(type(dest),"Character")==0&&strcmp(type(src),"Character")==0)
		*(char*)dest.data = *(char*)src.data;
	else
		printf("Incompatible Types!\n");
}
int cmpCharacter(Character obj, Character obj2)
{
	if(strcmp(type(obj),"Character")==0&&strcmp(type(obj2),"Character")==0)
		return *(char*)obj.data-*(char*)obj2.data;
	else
	{
		printf("Incompatible Types!\n");
		return INT_MIN;
	}
}
Character newCharacter(char data)
{
	Character* obj = (Character *) malloc(sizeof(Character));
	obj->data = malloc(sizeof(void*));
	*(char*)obj->data = data;
	obj->print = printCharacter;
	obj->copy  = cpyCharacter;
	obj->compare = cmpCharacter;
	obj->type_string = (char *) malloc(sizeof("Character"));
	strcpy(obj->type_string, "Character");
	return *obj;
}

//For String Wrapper
void printString(String obj)
{
	if(strcmp(type(obj),"String")==0)
	{
		if(obj.data) printf("\"%s\"",(char*)obj.data);
		else printf("NIL");
	}
	else
		printf("Not a String!\n");
}
void cpyString(String dest, String src)
{
	if(strcmp(type(dest),"String")==0&&strcmp(type(src),"String")==0)
		strcpy((char*)dest.data,(const char*)src.data);
	else
		printf("Incompatible Types!\n");
}
int cmpString(String obj, String obj2)
{
	if(strcmp(type(obj),"String")==0&&strcmp(type(obj2),"String")==0)
		return strcmp((const char*)obj.data,(const char*)obj2.data);
	else
	{
		printf("Incompatible Types!\n");
		return INT_MIN;
	}
}
String newString(const char* data)
{
	String* obj = (String *) malloc(sizeof(String));
	obj->data = malloc(sizeof(void*));
	strcpy((char *)obj->data,data);
	obj->print = printString;
	obj->copy  = cpyString;
	obj->compare = cmpString;
	obj->type_string = (char *) malloc(sizeof("String"));
	strcpy(obj->type_string, "String");
	return *obj;
}
