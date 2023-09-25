#include "sort.h"

/**
 * shell_sort - sorts an array using the shell sort algorithm
 * @array: the array to sort
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t interval, i, j;
	int holder;

	for (interval = 1; interval < size / 3; interval = interval * 3 + 1);
	while (interval > 0)
	{
		for (j = interval; j < size; j++)
		{
			for (i = j; i >= interval; i -= interval)
			{
				if (array[i] >= array[i - interval])
					break;
				holder = array[i];
				array[i] = array[i - interval];
				array[i - interval] = holder;
			}
		}
		interval /= 3;
		print_array(array, size);
	}
}
