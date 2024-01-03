#include "type_wrapper.h"
#include "utilities.h"

void main()
{
	Integer x = newInteger(10);
	Integer y = newInteger(20);
	printf("x_Value: "); x.print(x); printf("\n");
	printf("y_Value: "); y.print(y); printf("\n");
	printf("x + y = %d\n",Integer2int(x)+Integer2int(y));
	int cmp_res = x.compare(x, y);
	printf("Comparison Result: %d\n\n",cmp_res);
	
	Float x2 = newFloat(12.3);
	Float y2 = newFloat(2.9);
	printf("x2_Value: "); x2.print(x2); printf("\n");
	printf("y2_Value: "); y2.print(y2); printf("\n");
	 cmp_res = x2.compare(x2, y2);
	printf("Comparison Result: %d\n\n",cmp_res);
	
	String x3 = newString("Hello");
	String y3 = newString("World");
	printf("x3_Value: "); x3.print(x3); printf("\n");
	printf("y3_Value: "); y3.print(y3); printf("\n");
	 cmp_res = x3.compare(x3, y3);
	printf("Comparison Result: %d\n\n",cmp_res);
}
