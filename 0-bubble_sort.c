#include "sort.h"
#include <stddef.h>
#include <stdio.h>

/**
 *bubble_sort - sorts an array of integers in ascending order
 *@array: is the array
 *@size: is the size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp;

	for (j = 0; j < size; j++)
	{
		for (i = 0; i < size - 1; i++)
			if (array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
	}
}
