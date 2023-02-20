

#define _CRT_SECURE_NO_WARNING

#include <stdio.h>
#include <stdlib.h>
#include "3.h"

void fill(int* vector, int size,int value) {

	printf("fill num\n");
	for (int i = 0; i < size; i++)
	{
		vector[i] = value;
	}
}


int find(int* vector, int size, int value) {

	for (int i = 0; i < size; i++)
	{
		if (value == vector[i])
		{
			return i;
		}
	}
}
