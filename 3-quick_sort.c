#include "sort.h"

/**
 * swap - swap two numbers
 * @a: first number
 * @b: second number
 **/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - function that splits array around pivot
 * @arr: parameter
 * @first: parameter
 * @last: parameter
 * @size: parameter
 * Return: i
 */
int partition(int *arr, int first, int last, size_t size)
{
	int pivot = arr[last];
	int i = first;
	int j;

	for (j = first; j < last; j++)
	{
		if (arr[j] <= pivot)
		{
			swap(&arr[i], &arr[j]);
			if (i != j)
				print_array(arr, size);
			i++;
		}
	}
	swap(&arr[i], &arr[last]);
	if (i != j)
		print_array(arr, size);
	return (i);
}

/**
 * quickSort - function that sorts a part of the list
 * @arr: input
 * @first: parameter
 * @last: parameter
 * @size: input
 * Return: nothing
 */
void quickSort(int *arr, int first, int last, size_t size)
{
	int pivot;

	if (first < last)
	{
		pivot = partition(arr, first, last, size);
		quickSort(arr, first, pivot - 1, size);
		quickSort(arr, pivot + 1, last, size);
	}
}

/**
 * quick_sort - quick sort method array
 * @array: input
 * @size: input
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quickSort(array, 0, size - 1, size);
}
