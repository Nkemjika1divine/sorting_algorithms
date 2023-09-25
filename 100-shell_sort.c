#include "sort.h"

/**
 * shell_sort - sorts an array using the shell sort algorithm
 * @array: the array to sort
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int holder;

	if (array != NULL && size > 1)
	{
		for (gap = 1; gap < size / 3; gap = gap * 3 + 1);
		while (gap > 0)
		{
			for (j = gap; j < size; j++)
			{
				for (i = j; i >= gap; i -= gap)
				{
					if (array[i] >= array[i - gap])
						break;
					holder = array[i];
					array[i] = array[i - gap];
					array[i - gap] = holder;
				}
			}
			gap /= 3;
			print_array(array, size);
		}
	}
}
