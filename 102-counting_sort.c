#include "sort.h"
/**
 * counting_sort - sorts an array of integers in ascending
 * order using the Counting sort algorithm
 * @array: array of int
 * @size: size
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	size_t i = 0;
	int max = 0;
	int index;
	int *new;
	int *output;
	int value = 0;
	int j = 0;

	if (size == 0 || array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	new = malloc((max + 1) * sizeof(int));
	for (j = 0; j < (max + 1); j++)
		new[j] = 0;
	for (i = 0; i < size; i++)
	{
		value = array[i];
		new[value] = 1;
	}
	for (j = 1; j < max + 1; j++)
		new[j] = new[j] + new[j - 1];
	print_array(new, max + 1);
	output = malloc(size * sizeof(int));
	for (i = 0; i < size; i++)
	{
		index = new[array[i]];
		output[index - 1] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(new);
	free(output);
}
