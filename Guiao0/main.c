#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "3.h"


int main() {

	int Vector[3];
	int Value;

	fill(Vector,3,0);


	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", Vector[i]);

	}

	printf("num ?:");
	scanf("%d", &Value);
	int p = find(Vector, 3, Value);
	printf("num found in %d\n", p);



}
