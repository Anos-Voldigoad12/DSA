#ifndef TYPE_WRAPPER
#include "type_wrapper.h"
#endif

int Integer2int(Integer obj)
{
	if(strcmp(type(obj),"Integer")==0)
	{
		return *(int *)obj.data;
	}
	else
	{
		printf("Not an Integer!\n");
		return INT_MIN;
	}
}
float Float2float(Float obj)
{
	if(strcmp(type(obj),"Float")==0)
	{
		return *(float *)obj.data;
	}
	else
	{
		printf("Not a Float!\n");
		return (float)INT_MIN;
	}
}
double Double2double(Double obj)
{
	if(strcmp(type(obj),"Double")==0)
	{
		return *(double *)obj.data;
	}
	else
	{
		printf("Not a Double!\n");
		return (double)INT_MIN;
	}
}
char Character2char(Character obj)
{
	if(strcmp(type(obj),"Character")==0)
	{
		return *(char *)obj.data;
	}
	else
	{
		printf("Not a Character!\n");
		return '\0';
	}
}
char* String2str(String obj)
{
	if(strcmp(type(obj),"String")==0)
	{
		return (char *)obj.data;
	}
	else
	{
		printf("Not a String!\n");
		return NULL;
	}
}
