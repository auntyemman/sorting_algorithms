#include "sort.h"
/**
 * swap_root - swaps root node
 * @array: array
 * @root: root of heap
 * @hi: hi
 * @size: size
 * Return: ...
 */
void swap_root(int *array, size_t root, size_t hi, size_t size)
{
	size_t lo = 0, mi = 0, tmp = 0;
	int aux = 0;

	while ((lo = (2 * root + 1)) <= hi)
	{
		tmp = root;
		mi = lo + 1;
		if (array[tmp] < array[lo])
			tmp = lo;
		if (mi <= hi && array[tmp] < array[mi])
			tmp = mi;
		if (tmp == root)
			return;
		aux = array[root];
		array[root] = array[tmp];
		array[tmp] = aux;
		print_array(array, size);
		root = tmp;
	}
}

/**
 * heap_sort - sorts using heap method
 * @array: array
 * @size: size
 * Return: ...
 */
void heap_sort(int *array, size_t size)
{
	size_t hi = 0, gap = 0;
	int tmp = 0;

	if (array == NULL || size < 2)
		return;
	for (gap = (size - 2) / 2; 1; gap--)
	{
		swap_root(array, gap, size - 1, size);
		if (gap == 0)
			break;
	}
	hi = size - 1;
	while (hi > 0)
	{
		tmp = array[hi];
		array[hi] = array[0];
		array[0] = tmp;
		print_array(array, size);
		hi--;
		swap_root(array, 0, hi, size);
	}
}