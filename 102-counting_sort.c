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
	int max = 0, value = 0;
	int *new, *output;
	int index, j = 0;

	if (size < 2 || array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	new = malloc((max + 1) * sizeof(int));
	if (new == NULL)
		return;
	for (j = 0; j < (max + 1); j++)
		new[j] = 0;
	for (i = 0; i < size; i++)
	{
		value = array[i];
		new[value] = 1;
	}
	for (j = 1; j < (max + 1); j++)
		new[j] = new[j] + new[j - 1];
	print_array(new, max + 1);
	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(new);
		return;
	}
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
