#include "sort.h"

/**
 * counting_sort - rgis sorts an array usijg thecountung sort algorithm
 * @array: the rray to sot
 * @sise: suze if the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i, j, k, index;
	int *count, *sorted, max;

	max = findmax(array, size);
	index = (size_t)max;
	count = malloc(sizeof(int) * (index + 1));
	if (count == NULL)
		return;

	for (i = 0; i < index + 1; i++)
		count[i] = 0;

	for (j = 0; j < size; j++)
		count[array[j]]++;

	for (k = 1; k < index + 1; k++)
		count[k] += count[k - 1];
	print_array(count, index + 1);

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
	{
		free(count);
		return;
	}
	for (j = size - 1; j--;)
		sorted[--count[array[j]]] = array[j];

	for (i = 0; i < size; i++)
		array[i] = sorted[i];

	free(count);
	free(sorted);
}


/**
 * findmax - this finds tge maximum element in an array
 * @array: tge array
 * @size: size of the array
 *
 * Return: maximum element
 */
int findmax(int *array, size_t size)
{
	int max = 0;
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
