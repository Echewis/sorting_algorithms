#include "sort.h"

void swap_the_int(int *a, int *b);
int lomuto_part(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);
/**
 * swap_the_int - this will swap two ints
 * @a: this is the first number to be swaped
 * @b: this the second number to be swaped
 */
void swap_the_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;

}
/**
 * lomuto_part - this will oder the subset of an array of integer
 * in accordance to lomuto partintion scheme
 * @array: The array of integers
 * @left: this is the starng of the index of the subset of order
 * @right: This is the end of the subset of the order
 * @size: this is the size of the integers
 * Return: It will return the final subset to the order
 */

int lomuto_part(int *array, size_t size, int left, int right)
{
	int *pivot, up, down;

	pivot = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *pivot)
		{
			if (up < down)
			{
				swap_the_int(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *pivot)
	{
		swap_the_int(array + up, pivot);
		print_array(array, size);
	}
	return (up);
}
/**
 * lomuto_sort - this will implement quicksort algorithm
 * @array: this is the array to be sorted
 * @size: This is the size to be sorted
 * @left: This is the statrting of the array
 * @right: This is the end of the array
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int direction;

	if (right - left > 0)
	{
		direction = lomuto_part(array, size, left, right);
		lomuto_sort(array, size, left, direction - 1);
		lomuto_sort(array, size, direction + 1, right);
	}
}
/**
 * quick_sort - This will sort  an array of integer in an ascending
 * @array: This is the array of the integer
 * @size: This is the size of the integer
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
