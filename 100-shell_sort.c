#include "sort.h"

/**
 * swap_ints - func to Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gab, i, z;

	if (array == NULL || size < 2)
		return;

	for (gab = 1; gab < (size / 3);)
		gab = gab * 3 + 1;

	for (; gab >= 1; gab /= 3)
	{
		for (i = gab; i < size; i++)
		{
			z = i;
			while (z >= gab && array[z - gab] > array[z])
			{
				swap_ints(array + z, array + (z - gab));
				z -= gab;
			}
		}
		print_array(array, size);
	}
}
