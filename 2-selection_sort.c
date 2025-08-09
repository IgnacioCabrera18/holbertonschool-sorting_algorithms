#include "sort.h"
#include <stddef.h>
#include <stdio.h>

/**
 * selection_sort - sort an array of int 
 * @array: pointer to array
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)/*si el min no esta en la posicion actual intercambiar*/
		{
			temp = array[min];
			array[min] = array[i];
			array[i] = temp;
		}
	}
}
