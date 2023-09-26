#include "sort.h"

/**
 * merge_sort - sorts wn array usibg merge sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t ub = size - 1, lb = 0;
	int *b;

	if (array == NULL || size < 2)
		return;

	b = malloc(sizeof(int) * size);
	if (b == NULL)
		return;

	ms(array, lb, ub, b);
	free(b);
}

/**
 * ms - this breaks the array down to sublists
 * @a: the array to break
 * @lb: the lower bound
 * @ub: the upper bound
 * @b: the array to be copied unto
 */
void ms(int *a, size_t lb, size_t ub, int *b)
{
	size_t mid;

	if (lb < ub)
	{
		mid = (lb + ub) / 2;
		ms(a, lb, (mid - 1), b);
		ms(a, mid, ub, b);

		merge(a, lb, mid, ub, b);
	}
}

/**
 * merge - merges the sorted sublists
 * @a: array to sort
 * @lb: the lower bound
 * @mid: midpoint of the sublist
 * @ub: the upper bound
 * @b: the array to be copied into
 */
void merge(int *a, size_t lb, size_t mid, size_t ub, int *b)
{
	size_t i = lb, j = mid, k = lb;

	while (i <= mid && j <= ub)
	{
		if (a[i] <= a[j])
		{
			b[k] = a[i];
			i++;
		}
		else
		{
			b[k] = a[j];
			j++;
		}
		k++;
	}
	if (i > mid)
	{
		while (j <= ub)
		{
			b[k] = a[j];
			j++;
			k++;
		}
	}
	else
	{
		while (i <= mid)
		{
			b[k] = a[i];
			i++;
			k++;
		}
	}
	for (k = lb; k <= ub; k++)
		a[k] = b[k];
}
