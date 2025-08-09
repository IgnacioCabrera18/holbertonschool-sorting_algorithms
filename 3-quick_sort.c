#include "sort.h"

void print_array(const int *array, size_t size);

/**
 *swap_and_print - Intercambia dos elementos de la matriz y imprime.
 *@array: Puntero al primer elemento de la matriz.
 *@size: Número total de elementos de la matriz.
 *@idx1: Indice del primer elemento a intercambiar.
 *@idx2: Indice del segundo elemento a intercambiar.
 */

void swap_and_print(int *array, size_t size, int idx1, int idx2)
{
	int temp;

	if (idx1 != idx2)
	{
		temp = array[idx1];
		array[idx1] = array[idx2];
		array[idx2] = temp;
		print_array(array, size);
	}
}

/**
 *lomuto_partition - Particiona un subarray utilizando el esquema de Lomuto.
 *@array: Puntero al primer elemento de la matriz.
 *@low: Indice inicial de la submatriz a particionar.
 *@high: Indicie final de la submatriz.
 *@size: Número total de elementos de la matriz
 *Return: Indice final del pivote tras la partición
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			swap_and_print(array, size, i, j);
			i++;
		}
	}
	swap_and_print(array, size, i, high);
	return (i);
}

/**
 *quick_sort_recursive - Aplica recursivamente quick_sort
 *@array: Puntero al primer elemento de la matriz.
 *@low: Indice inicial de la porción del array a ordena.
 *@high: Indice final de la porción del array a ordenar
 *@size: Número total de elementos de la matriz.
 */

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, p - 1, size);
		quick_sort_recursive(array, p + 1, high, size);
	}
}

/**
 *quick_sort - Ordena una matriz de enteros en orden ascendente.
 *@array: Puntero al primer elemento de la matriz.
 *@size: Número total de elementos de la matriz
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}
