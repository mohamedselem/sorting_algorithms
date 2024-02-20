#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

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
 * hoare_partition - func to Order a subset of an array of integers.
 * @array: The array of integers.
 * @size: The size of array.
 * @left: The starting index of the subset.
 * @right: The ending index of the subset.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pvt, above, below;

	pvt = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pvt);
		do {
			below--;
		} while (array[below] > pvt);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int pt;

	if (right - left > 0)
	{
		pt = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, pt - 1);
		hoare_sort(array, size, pt, right);
	}
}

/**
 * quick_sort_hoare - func to Sort array of integers in ascending order.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
