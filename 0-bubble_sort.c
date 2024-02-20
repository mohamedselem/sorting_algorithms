#include "sort.h"

/**
 * swap_ints - func to Swap two integers in an array.
 * @a: The first integer to be swapped.
 * @b: The second integer to be swapped.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - func to Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of array.
 *
 * Description: Prints array after each swapping.
 */
void bubble_sort(int *array, size_t size)
{
	size_t z, lens = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (z = 0; z < lens - 1; z++)
		{
			if (array[z] > array[z + 1])
			{
				swap_ints(array + z, array + z + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		lens--;
	}
}
