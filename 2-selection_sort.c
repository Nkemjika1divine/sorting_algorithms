#include "sort.h"

/**
 * selection_sort - this sorts an array using the selection sortinv algorithm
 * @array: thearry to sort
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int holder;

	if (array != NULL && size > 0)
	{
		for (i = 0; i < (size - 1); i++)
		{
			min = i;
			for (j = i + 1; j < size; j++)
			{
				if (array[j] < array[min])
					min = j;
			}
			if (min != i)
			{
				holder = array[i];
				array[i] = array[min];
				array[min] = holder;
				print_array(array, size);
			}
		}
	}
}
