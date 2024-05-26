#include <stdio.h>

int linearSearch(int array[], int N, int item, int *time_complexity);
int binarySearch(int array[], int N, int item, int *time_complexity);
int binarySearchRecursive(int array[], int left, int right, int item, int *time_complexity);
void bubbleSort(int array[], int N, int *time_complexity);
void selectionSort(int array[], int N, int *time_complexity);
void insertionSort(int array[], int N, int *time_complexity);

int main()
{
    int i;
    int time_complexity = 0;
    int array[] = {12, 6, 4, 5, 3, 9, 15, 11};
    int size = sizeof(array) / sizeof(array[0]);

    // bubbleSort(array, size, &time_complexity); // Best Complexity -> O(n^2) || Worst Complexity -> O(n^2)
    // selectionSort(array, size, &time_complexity); // Best Complexity -> O(n^2) || Worst Complexity -> O(n^2)
    insertionSort(array, size, &time_complexity); // Best Complexity -> O(n) || Worst Complexity -> O(n^2)
    printf("Sorted array: ");
    for (i = 0; i < size; i++)
        printf("%d, ", array[i]);

    printf("\nSort time complexity: %d\n", time_complexity);

    time_complexity = 0;
    printf("\nElement found at index: %d\n", linearSearch(array, size, 11, &time_complexity));
    printf("Linear Search time complexity: %d\n", time_complexity);

    time_complexity = 0;
    printf("\nElement found at index: %d\n", binarySearch(array, size, 11, &time_complexity));
    // printf("\nElement found at index: %d\n", binarySearchRecursive(array, 0, size - 1, 11, &time_complexity));
    printf("Binary Search time complexity: %d\n", time_complexity);

    return 0;
}


int linearSearch(int array[], int N, int item, int *time_complexity) // Best Complexity -> O(1) || Worst Complexity -> O(n)
{
    int i;
    for (i = 0; i < N; i++)
    {
        (*time_complexity)++;
        if (array[i] == item)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int array[], int N, int item, int *time_complexity) // Best Complexity -> O(1) || Worst Complexity -> O(logn)
{
    int left = 0, right = N - 1, mid;
    while (left <= right)
    {
        (*time_complexity)++;
        mid = (left + right) / 2;
        if (array[mid] == item)
            return mid;
        else if (array[mid] < item)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int binarySearchRecursive(int array[], int left, int right, int item, int *time_complexity) // Best Complexity -> O(1) || Worst Complexity -> O(logn)
{
    if (left <= right)
    {
        (*time_complexity)++;
        int mid = (left + right) / 2;
        if (array[mid] == item)
            return mid;
        else if (array[mid] < item)
            return binarySearchRecursive(array, mid + 1, right, item, time_complexity);
        else
            return binarySearchRecursive(array, left, mid - 1, item, time_complexity);
    }
    return -1;
}

void bubbleSort(int array[], int N, int *time_complexity) // Best Complexity -> O(n^2) || Worst Complexity -> O(n^2)
{
    int i, j, tmp;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N - i - 1; j++)
        {
            (*time_complexity)++;
            if (array[j] > array[j + 1])
            {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

void selectionSort(int array[], int N, int *time_complexity) // Best Complexity -> O(n^2) || Worst Complexity -> O(n^2)
{
    int i, j, min, temp;
    for (i = 0; i < N - 1; i++)
    {
        min = i;
        for (j = i + 1; j < N; j++)
        {
            (*time_complexity)++;
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        temp = array[min];
        array[min] = array[i];
        array[i] = temp;
    }
}

void insertionSort(int array[], int N, int *time_complexity) // Best Complexity -> O(n) || Worst Complexity -> O(n^2)
{
    int i, j, tmp;
    for (i = 1; i < N; i++)
    {
        j = i;
        while (j > 0 && array[j - 1] > array[j])
        {
            (*time_complexity)++;
            tmp = array[j - 1];
            array[j - 1] = array[j];
            array[j] = tmp;
            j--;
        }
        (*time_complexity)++;
    }
}
