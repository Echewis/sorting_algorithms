#include "sort.h"

/**
 * swap_the_int - this will swap the int in an array
 * @a: this is the first integer
 * @b: this is the second integer
 */

void swap_the_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - This will sort the integers in an ascending way using
 * the selection sorting algorithm
 * @array: This is the array of integer
 * @size: This is the size of array
 */

void selection_sort(int *array, size_t size)
{
	int *main;
	size_t a, b;
	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		main = array + a;
		for (b = a + 1; b < size; b++)
			main = (array[b] < *main) ? (array + b) : main;

		if ((array + a) != main)
		{
			swap_the_int(array + a, main);
			print_array(array, size);
		}
	}
}
