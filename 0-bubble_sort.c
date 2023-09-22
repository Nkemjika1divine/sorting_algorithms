#include "sort.h"

/**
 * bubble_sort - performs the sorting using bubble sort algorith
 * @array: the array of integers to sort
 * @size: size of the arrayif integers
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, count, flag, iter;
	int holder;

	iter = 0;
	count = 1;
	while (iter != size)
	{
		flag = 0;
		for (i = 0; i < (size - count); i++)
		{
			if (array[i] > array[i + 1])
			{
				flag = 1;
				holder = array[i];
				array[i] = array[i + 1];
				array[i + 1] = holder;
				print_array(array, size);
			}
		}
		count += 1;
		iter += 1;
		if (flag == 0)
			break;
	}
}
