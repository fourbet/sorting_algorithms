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
	size_t gap = 1;
	int i = 0;
	size_t ref;
	size_t j = 0;
	int ok = 0;
	int k = 0;
	int l = 0;

	gap = 4;
	while (gap >= 1 && ok <= 1)
	{
		while(j < size)
		{
			i = 0;
			ref = 0;
			while((ref * i + j) < size)
			{
				i++;
				if (i * gap + j >= size)
					break;
				if (array[ref + j] > array[i * gap + j])
				{
					swap(&array[ref + j], &array[i * gap + j]);
					k = 0;
					l = j + 1;
					if (gap == 1)
					{
						while (l > 0)
						{
							if (array[l] < array[l - 1])
							{
								swap(&array[l], &array[l - 1]);
							}
							l--;
						}
					}
					else
					{
						while (k < i)
						{
							if (array[gap * k + j] > array[gap * (k + 1) + j])
							{
								swap(&array[gap * k + j], &array[gap * (k + 1) + j]);
							}
							k++;
						}
					}
				}
				ref = i * gap;
			}
			j += 1;
		}
		print_array(array, size);
		j = 0;
		gap /= 3;
		if (gap == 1)
			ok +=1;
	}
}

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
