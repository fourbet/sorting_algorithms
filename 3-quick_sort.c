#include "sort.h"
/**
 * partition - reorder the array
 *
 * @array: array of int
 * @size: size of the array
 * @left: index from Left
 * @right: index from right
 *
 * Return: void
 */
int partition(int *array, int left, int right, size_t size)
{
	int pivot;
	int i;
	int j;
	int tmp;

	pivot = array[right];
	i = (left - 1);
	for (j = left; j <= right - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (array[i] != array[j])
				print_array(array, size);
		}
	}
	tmp = array[i + 1];
	array[i + 1] = array[right];
	array[right] = tmp;
	if (array[i + 1] != array[right])
		print_array(array, size);
	return (i + 1);
}
/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: array of int
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	int idx_l;
	int idx_r;

	if (size == 0 || array == NULL)
		return;
	idx_l = 0;
	idx_r = size - 1;
	quicksort(array, idx_l, idx_r, size);
}
/**
 * quicksort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: array of int
 * @size: size of the array
 * @idx_l: index from Left
 * @idx_r: index from right
 *
 * Return: void
 */
void quicksort(int *array, int idx_l, int idx_r, size_t size)
{
	int pi;

	if (idx_l < idx_r)
	{
		pi = partition(array, idx_l, idx_r, size);
		quicksort(array, idx_l, pi - 1, size);
		quicksort(array, pi + 1, idx_r, size);
	}
}
