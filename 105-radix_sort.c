#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - func to Get the maximum value in array.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in array.
 */
int get_max(int *array, int size)
{
	int maximum, z;

	for (maximum = array[0], z = 1; z < size; z++)
	{
		if (array[z] > maximum)
			maximum = array[z];
	}

	return (maximum);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t z;

	for (z = 0; z < size; z++)
		count[(array[z] / sig) % 10] += 1;

	for (z = 0; z < 10; z++)
		count[z] += count[z - 1];

	for (z = size - 1; (int)z >= 0; z--)
	{
		buff[count[(array[z] / sig) % 10] - 1] = array[z];
		count[(array[z] / sig) % 10] -= 1;
	}

	for (z = 0; z < size; z++)
		array[z] = buff[z];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int maximum, sig, *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	maximum = get_max(array, size);
	for (sig = 1; maximum / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buffer);
		print_array(array, size);
	}

	free(buffer);
}
