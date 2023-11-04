#include "map.h"
#include "utilities.h"

void main()
{
	int k,d;
	map* m = newMap(genKeyFromInt,isEqualInt,cpyInt,cpyInt);
	k = 22; d = 2;
	putItem(m,&k,&d);
	k = 10; d = 1;
	putItem(m,&k,&d);
	k = 42; d = 3;
	putItem(m,&k,&d);
	k = 19; d = 1;
	putItem(m,&k,&d);
	k = 7; d = 2;
	putItem(m,&k,&d);
	printf("MAP [size:%d]\n",m->size);
	printMap(m,printInt,printInt);
	printf("[%d] : ",k); printInt(getVal(m,&k)); printf("\n");
	k = 42;
	removeItem(m,&k);
	_cleanMap(m);
	k = 22; d = 3;
	putItem(m,&k,&d);
	printf("MAP [size:%d]\n",m->size);
	printMap(m,printInt,printInt);
	void** keys = getKeys(m);
	int i;
	printf("Keys: ");
	for(i=0;i<m->size;i++)
	{
		printInt(*(keys+i)); printf(", ");
	}
	printf("\b\b \n");
	void** vals = getVals(m);
	printf("Vals: ");
	for(i=0;i<m->size;i++)
	{
		printInt(*(vals+i)); printf(", ");
	}
	printf("\b\b \n");
	
//	double k2,d2;
//	map* m2 = newMap(genKeyFromDouble,isEqualDouble,cpyDouble,cpyDouble); 
//	k2 = 22.4; d2 = 2.4;
//	putItem(m2,&k2,&d2);
//	k2 = 10.3; d2 = 1.9;
//	putItem(m2,&k2,&d2);
//	k2 = 42.5; d2 = 3.6;
//	putItem(m2,&k2,&d2);
//	k2 = 19.1; d2 = 1.7;
//	putItem(m2,&k2,&d2);
//	k2 = 7.8; d2 = 2.6;
//	putItem(m2,&k2,&d2);
//	printf("MAP [size:%d]\n",m2->size);
//	printMap(m2,printDouble,printDouble);
//	printf("[%.3f] : ",k2); printDouble(getVal(m2,&k2)); printf("\n");
//	k2 = 42.5;
//	removeItem(m2,&k2);
//	_cleanMap(m2);
//	printf("MAP [size:%d]\n",m2->size);
//	printMap(m2,printDouble,printDouble);
//	
//	char k3[25],d3[25];
//	map* m3 = newMap(genKeyFromString,isEqualString,cpyString,cpyString); 
//	strcpy(k3,"alu"); strcpy(d3,"1");
//	putItem(m3,&k3,&d3);
//	strcpy(k3,"cu"); strcpy(d3,"2");
//	putItem(m3,&k3,&d3);
//	strcpy(k3,"mem"); strcpy(d3,"3");
//	putItem(m3,&k3,&d3);
//	printf("MAP [size:%d]\n",m3->size);
//	printMap(m3,printString,printString);
//	printf("[%s] : ",k3); printString(getVal(m3,&k3)); printf("\n");
//	//k3 = "mem";
//	removeItem(m3,&k3);
//	_cleanMap(m3);
//	printf("MAP [size:%d]\n",m3->size);
//	printMap(m3,printString,printString);
//	
//	
//	char k4,d4;
//	map* m4 = newMap(genKeyFromChar,isEqualChar,cpyChar,cpyChar); 
//	k4 = 'a'; d4 = '0';
//	putItem(m4,&k4,&d4);
//	k4 = 'b'; d4 = '4';
//	putItem(m4,&k4,&d4);
//	k4 = 'c'; d4 = '2';
//	putItem(m4,&k4,&d4);
//	k4 = 'd'; d4 = '1';
//	putItem(m4,&k4,&d4);
//	k4 = 'e'; d4 = '3';
//	putItem(m4,&k4,&d4);
//	printf("MAP [size:%d]\n",m4->size);
//	printMap(m4,printChar,printChar);
//	printf("[%c] : ",k4); printChar(getVal(m4,&k4)); printf("\n");
//	k4 = 'c';
//	removeItem(m4,&k4);
//	_cleanMap(m4);
//	printf("MAP [size:%d]\n",m4->size);
//	printMap(m4,printChar,printChar);
}
