#include <stdio.h>
#include "labo.h"

int n = 5;
int elements[] = { 78, 45, 180, 28, 30 };

void insertionSort(int elements[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int y = i;
		while (y > 0 && elements[y] < elements[y - 1])
		{
			int temp = elements[y];
			elements[y] = elements[y - 1];
			elements[y - 1] = temp;
			--y;
		}
	}
}

void quickSort(int* elements, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int L = left;
	int R = right;
	int pivot = elements[(left + right) / 2];

	while (left <= right)
	{
		while (elements[left] < pivot)
		{
			left++;
		}

		while (elements[right] > pivot)
		{
			right--;
		}

		if (left <= right)
		{
			int temp = elements[left];
			elements[left] = elements[right];
			elements[right] = temp;
			left++;
			right--;
		}
	}
	int index = left;
	quickSort(elements, L, index - 1);
	quickSort(elements, index, R);
}
