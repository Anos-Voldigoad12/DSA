#include <stdio.h>
#include <string.h>

//For Int
int genKeyFromInt(void *data)
{
	return ( *(int*)(data) )%10;
}
int isEqualInt(void *data, void *se)
{
	return *(int*)data == *(int*)se;
}
void cpyInt(void *dest, void *src)
{
	*(int*)dest = *(int*)src;
}
void printInt(void *data)
{
	if(data) printf("%d",*(int*)data);
	else printf("NIL");
}

//For Double
int genKeyFromDouble(void *data)
{
	return ( (int)(*(double*)(data)) )%10;
}
int isEqualDouble(void *data, void *se)
{
	return *(double*)data == *(double*)se;
}
void cpyDouble(void *dest, void *src)
{
	*(double*)dest = *(double*)src;
}
void printDouble(void *data)
{
	if(data) printf("%.3f",*(double*)data);
	else printf("NIL");
}

//For Character
int genKeyFromChar(void *data)
{
	return ( *(char*)(data) )%10;
}
int isEqualChar(void *data, void *se)
{
	return *(char*)data == *(char*)se;
}
void cpyChar(void *dest, void *src)
{
	*(char*)dest = *(char*)src;
}
void printChar(void *data)
{
	if(data) printf("\'%c\'",*(char*)data);
	else printf("NIL");
}

//For String
int genKeyFromString(void *data)
{
	const char* str = (const char*) data;
	int i,sum = 0;
	for(i=0;str[i]!='\0';i++)
	{
		sum += str[i];
	}
	return sum%10;
}
int isEqualString(void *data, void *se)
{
	const char* str = (const char*) data;
	const char* str2 = (const char*) data;
	return strcmp(str,str2)==0;
}
void cpyString(void *dest, void *src)
{
	strcpy((char*)dest,(const char*)src);
}
void printString(void *data)
{
	if(data) printf("\"%s\"",(char*)data);
	else printf("NIL");
}
