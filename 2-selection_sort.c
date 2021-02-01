#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 *
 * @array: array of int
 * @size: size of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	int idx_s;
	size_t idx_l;
	int s;
	int tmp;
	int ok;

	if (size == 0 || array == NULL)
		return;

	for (idx_l = 0; idx_l < size - 1; idx_l++)
	{
		s = array[idx_l];
		for (i = idx_l; i < size; i++)
		{
			if (array[i] < s)
			{
				s = array[i];
				idx_s = i;
				ok = 1;
			}
		}
		if (ok == 1)
		{
			tmp = array[idx_l];
			array[idx_l] = array[idx_s];
			array[idx_s] = tmp;
			print_array(array, size);
			ok = 0;
		}
	}
}
