#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "labo.h"

void insertionSort(int elements[], int n)
{
    int ValeurTempo, i2;
    //first loop to compare every number in elements
    for (int i = 1; i < n; i++)
    {
        ValeurTempo = elements[i];
        i2 = i - 1;
        //second loop with condition to compare every number in elements with each other
        while (i2 >= 0 && elements[i2] > ValeurTempo)
        {
            elements[i2 + 1] = elements[i2];
            i2 = i2 - 1;
        }
        //put the ValeurTempo (elements[i]) at his right sort place
        elements[i2 + 1] = ValeurTempo;
    }
}

void quickSort(int* elements, int left, int right)
{
    if (left < right)
    {
        int PartitionIndex = partitionSorting(elements, left, right);
        //code recursivity to sort both lower and higher part of the array
        quickSort(elements, left, PartitionIndex - 1);
        quickSort(elements, PartitionIndex + 1, right);
    }
}
int partitionSorting(int tab[], int left, int right)
{
    int pivot = tab[right];    // pivot
    int i = (left - 1);  // Index of smaller element

    for (int i2 = left; i2 <= right - 1; i2++)
    {
        if (tab[i2] <= pivot)
        {
            i++;
            swap(&tab[i], &tab[i2]);
        }
    }
    //put the pivot (tab[right]) at his right sort place
    swap(&tab[i + 1], &tab[right]);
    return (i + 1);
}
void swap(int* x, int* y)
{
    int Tempo = *x;
    *x = *y;
    *y = Tempo;
}