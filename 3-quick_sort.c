#include "sort.h"
/**
 * quick_sort - sorts an array in ascending order with Quick sort algo
 * @array: array to be sorted
 * @size: size
 * Return: ....
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}

/**
 * quick_sort_rec - ......
 * @array: array
 * @lower: lower
 * @higher: higher
 * @size: size
 * Return: ...
 */
void quick_sort_rec(int *array, int lower, int higher, size_t size)
{
	int lo_p = 0;

	if (lower < higher)
	{
		lo_p = lomuto_partition(array, lower, higher, size);
		quick_sort_rec(array, lower, lo_p - 1, size);
		quick_sort_rec(array, lo_p + 1, higher, size);
	}
}

/**
 * lomuto_partition - lomuto partition scheme
 * @array: array
 * @lower: lower
 * @higher: higher
 * @size: size
 * Return: ....
 */
int lomuto_partition(int *array, int lower, int higher, size_t size)
{
	int i = 0, j = 0, pivot = 0, aux = 0;

	pivot = array[higher];
	i = lower;

	for (j = lower; j < higher; ++j)
	{
		if (array[j] < pivot)
		{
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;

			if (aux != array[i])
				print_array(array, size);

			++i;
		}
	}
	aux = array[i];
	array[i] = array[higher];
	array[higher] = aux;
	if (aux != array[i])
		print_array(array, size);
	return (i);
}
