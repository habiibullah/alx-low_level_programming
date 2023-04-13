#include "search_algos.h"

/**
  * advanced_binary_recursive - Searches recursively for a value in a sorted
  *                             array of integers using binary search.
  * @array: A pointer to the first element of the [sub]array to search.
  * @beg: The starting index of the [sub]array to search.
  * @end: The ending index of the [sub]array to search.
  * @value: The value to search for.
  *
  * Return: If the value is not present, -1.
  *         Otherwise, the index where the value is located.
  *
  * Description: Prints the [sub]array being searched after each change.
  */
int advanced_binary_recursive(int *array, size_t beg, size_t end, int value)
{
	size_t i;

	if (end < beg)
		return (-1);

	printf("Searching in array: ");
	for (i = beg; i < end; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);

	i = beg + (end - beg) / 2;
	if (array[i] == value && (i == beg || array[i - 1] != value))
		return (i);
	if (array[i] >= value)
		return (advanced_binary_recursive(array, beg, i, value));
	return (advanced_binary_recursive(array, i + 1, end, value));
}

/**
  * advanced_binary - Searches for a value in a sorted array
  *                   of integers using advanced binary search.
  * @array: A pointer to the first element of the array to search.
  * @size: The number of elements in the array.
  * @value: The value to search for.
  *
  * Return: If the value is not present or the array is NULL, -1.
  *         Otherwise, the first index where the value is located.
  *
  * Description: Prints the [sub]array being searched after each change.
  */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
