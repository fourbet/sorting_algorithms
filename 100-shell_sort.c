#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm
 *
 * @array: array of int
 * @size: size of the array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 0, j, i, k;

	while (gap < size)
		gap = gap * 3 + 1;
	gap = gap / 3;
	for (; gap; gap = gap / 3)
	{
		for (j = 0; j < size - gap; j++)
		{
			for (i = 0; i < (size / (gap + j)); i++)
			{
				if (gap == 1 && i == size - 1)
					break;
				if (array[gap * (i + 1) + j] < array[gap * i + j])
				{
					swap(&array[gap * (i + 1) + j], &array[gap * i + j]);
					k = i;
					while (k > 0)
					{
						if (array[gap * (k - 1) + j] > array[gap * k + j])
						{
							swap(&array[gap * (k - 1) + j], &array[gap * k + j]);
						}
						k--;
					}
				}
			}
		}
		print_array(array, size);
	}
}
/**
 * swap - swap integers in array
 *
 *@a: int *
 *@b: int *
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
