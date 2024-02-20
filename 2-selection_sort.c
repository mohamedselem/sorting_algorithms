#include "sort.h"

/**
 * swap_ints - func to Swap two integers in an array.
 * @a: The first integer to be swap.
 * @b: The second integer to be swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *mine;
	size_t i, z;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		mine = array + i;
		for (z = i + 1; z < size; z++)
			mine = (array[z] < *mine) ? (array + z) : mine;

		if ((array + i) != mine)
		{
			swap_ints(array + i, mine);
			print_array(array, size);
		}
	}
}
