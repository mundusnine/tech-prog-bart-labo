#include "labo.h"


void insertionSort(int elements[], int n)
{
	int y;
	for (int i = 1; i < n; i++)
	{
		y = i;

		while (y > 0 && elements[y] < elements[y - 1])
		{
			int temp = elements[y];
			elements[y] = elements[y - 1];
			elements[y - 1] = temp;
			--y;
		}


	}
}

void quickSort(int* elements, int left, int right) {
	if (left >= right)
	{
		return;
	}

	int l = left;
	int r = right;
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

	quickSort(elements, l, index - 1);

	quickSort(elements, index, r);



}