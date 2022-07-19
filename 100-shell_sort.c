#include "sort.h"

/**
 * shell_sort - sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
int inner, outer;
int valueToInsert;
int interval = 1;
int i = 0;

while(interval <= (int) size/3)
	interval = interval*3 +1;


while(interval > 0) {

	for(outer = interval; outer < (int) size; outer++) {
		valueToInsert = array[outer];
		inner = outer;

		while(inner > interval -1 && array[inner - interval] >= valueToInsert) {
		array[inner] = array[inner - interval];
		inner -=interval;
		}

		array[inner] = valueToInsert;
	}

interval = (interval -1) /3;
print_array(array, size);
i++;
}
}
