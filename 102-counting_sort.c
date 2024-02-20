#include "sort.h"

/**
 * get_max - func to Get maximum value in array of integer.
 * @array: An array of integer.
 * @size: size of the array.
 *
 * Return: maximum integer in array.
 */
int get_max(int *array, int size)
{
	int mx, z;

	for (mx = array[0], z = 1; z < size; z++)
	{
		if (array[z] > mx)
			mx = array[z];
	}

	return (mx);
}

/**
 * counting_sort - func to Sort an array of integers in ascending order.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after.
 */
void counting_sort(int *array, size_t size)
{
	int *cnt, *sorted, max, z;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	cnt = malloc(sizeof(int) * (max + 1));
	if (cnt == NULL)
	{
		free(sorted);
		return;
	}

	for (z = 0; z < (max + 1); z++)
		cnt[i] = 0;
	for (z = 0; z < (int)size; z++)
		cnt[array[z]] += 1;
	for (z = 0; z < (max + 1); z++)
		cnt[z] += cnt[z - 1];
	print_array(cnt, max + 1);

	for (z = 0; z < (int)size; z++)
	{
		sorted[cnt[array[z]] - 1] = array[z];
		cnt[array[z]] -= 1;
	}

	for (z = 0; z < (int)size; z++)
		array[z] = sorted[z];

	free(sorted);
	free(cnt);
}
