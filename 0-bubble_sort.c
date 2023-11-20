#include "sort.h"


/**
 * swap_the_int - this will swap the two integer in an array
 * @a: This is the fisrt integer to be swaped
 * @b: This is the second integer ot be swaped
 */

void swap_the_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - This will sort for the array of integer in ascending order
 * @array: This is the array of integer to be sorted
 * @size: This is the size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t a, len = size;
	bool bubble = false;

	if (array == NULL || size < 2)
		return;

	while (bubble == false)
	{
		bubble = true;
		for (a = 0; a < len - 1; a++)
		{
			if (array[a] > array[a + 1])
			{
				swap_the_int(array + a, array + a + 1);
				print_array(array, size);
				bubble = false;
			}
		}
		len--;
	}
}
