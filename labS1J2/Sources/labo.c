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

	int show = right; // Pour print 
	for (int i = 0; i < show; i++)
	{
		printf("%d\n", elements[i]);
	}
	printf("Left = %d, Right = %d\n", left, right);
	printf("===========================================\n");
	
	



	int pivot = elements[(left + right) / 2];
	printf("Pivot %d\n", pivot); // run 1 = 682
	// left = 0 right = 7

	int l = left;
	int r = right;

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

		//left = 3 right = 7
		if (left <= right)
		{
			int temp = elements[left];
			elements[left] = elements[right];
			elements[right] = temp;
			left++;
			right--;
		}
		// 4 6

	}


	
	printf("Left = %d, Right = %d\n", left, right);
	
	if (left >= right)
	{
		for (int i = 0; i < show; i++)
		{
			printf("%d\n", elements[i]);
		}

		return;
	}



	int index = left;
	quickSort(elements, l, index - 1);
	quickSort(elements, index, r);


}