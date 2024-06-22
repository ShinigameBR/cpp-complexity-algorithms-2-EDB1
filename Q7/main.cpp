#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int *generateRandomArray(int N)
{
    srand(time(nullptr));

    int *randomArray = new int[N];

    for (int i = 0; i < N; ++i)
    {
        randomArray[i] = rand() % (N + 1);
    }

    return randomArray;
}

bool checkOrder(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void countingSort(int arr[], int n)
{
    if (n == 0)
        return;

    int max_val = arr[0];
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] > max_val)
        {
            max_val = arr[i];
        }
    }

    int *count = new int[max_val + 1]();
    for (int i = 0; i < n; ++i)
    {
        count[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max_val; ++i)
    {
        while (count[i] > 0)
        {
            arr[index++] = i;
            count[i]--;
        }
    }

    delete[] count;
}

void runTests()
{
    int sizes[] = {100, 1000, 10000, 100000, 500000};
    for (int n : sizes)
    {
        int *arr = generateRandomArray(n);
        int *arrCopy = new int[n];
        clock_t start = clock();
        clock_t end = clock();

        // Selection Sort
        copy(arr, arr + n, arrCopy);
        start = clock();
        selectionSort(arrCopy, n);
        end = clock();
        cout << "Selection Sort para " << n << " elementos durou " << double(end - start) / CLOCKS_PER_SEC << " segundos." << endl;

        // Merge Sort
        copy(arr, arr + n, arrCopy);
        start = clock();
        mergeSort(arrCopy, 0, n - 1);
        end = clock();
        cout << "Merge Sort para " << n << " elementos durou " << double(end - start) / CLOCKS_PER_SEC << " segundos." << endl;

        // // Counting Sort
        copy(arr, arr + n, arrCopy);
        start = clock();
        countingSort(arrCopy, n);
        end = clock();
        cout << "Counting Sort para " << n << " elementos durou " << double(end - start) / CLOCKS_PER_SEC << " segundos." << endl;

        delete[] arr;
        delete[] arrCopy;
    }
}

int main()
{
    runTests();
    return 0;
}