#include "sort.h"
#include <stddef.h>
#include <stdio.h>

/**
 *
 *
 *
 *
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp;

	for (j = 0; j < size; j++)
	{
		for (i = 0; i < size - 1; i++)
			if (i < size && array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
	}
}
