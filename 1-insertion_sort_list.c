#include "sort.h"
#include <stddef.h>
#include <stdio.h>

/**
 *insertion_sort_list - Insertion sort
 *@list: is a pointer to the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *actual, *temp, *auxiliar;

	if (*list == NULL || list == NULL || (*list)->next == NULL)
		return;

	actual = (*list)->next;
	while (actual)
	{
		temp = actual->prev;
		auxiliar = actual;
		while (temp &&  temp->n > auxiliar->n)
		{
			if (temp->prev)
				temp->prev->next = auxiliar;

			auxiliar->prev = temp->prev;
			temp->next = auxiliar->next;

			if (auxiliar->next)
				auxiliar->next->prev = temp;

			auxiliar->next = temp;
			temp->prev = auxiliar;

			if (auxiliar->prev == NULL)
				*list = auxiliar;

			print_list(*list);
			temp = auxiliar->prev;
		}
		actual = actual->next;
	}
}
