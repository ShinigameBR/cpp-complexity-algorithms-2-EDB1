#include <iostream>
using namespace std;

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

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void runTests()
{
    int arr1[] = {64, 25, 12, 22, 11};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Vetor original: ";
    printArray(arr1, n1);
    selectionSort(arr1, n1);
    cout << "Selection Sort: ";
    printArray(arr1, n1);
    cout << "Verificação: " << (checkOrder(arr1, n1) ? "Correto" : "Incorreto") << endl
         << endl;

    int arr2[] = {38, 27, 43, 3, 9, 82, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Vetor original: ";
    printArray(arr2, n2);
    mergeSort(arr2, 0, n2 - 1);
    cout << "Merge Sort: ";
    printArray(arr2, n2);
    cout << "Verificação: " << (checkOrder(arr2, n2) ? "Correto" : "Incorreto") << endl
         << endl;

    int arr3[] = {4, 2, 2, 8, 3, 3, 1};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "Vetor original: ";
    printArray(arr3, n3);
    countingSort(arr3, n3);
    cout << "Counting Sort: ";
    printArray(arr3, n3);
    cout << "Verificação: " << (checkOrder(arr3, n3) ? "Correto" : "Incorreto") << endl
         << endl;

    int arr4[] = {1, 2, 3, 4, 5};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    cout << "Vetor já ordenado: ";
    printArray(arr4, n4);
    cout << "Verificação: " << (checkOrder(arr4, n4) ? "Correto" : "Incorreto") << endl
         << endl;

    int arr5[] = {5, 4, 3, 2, 1};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    cout << "Vetor original: ";
    printArray(arr5, n5);
    selectionSort(arr5, n5);
    cout << "Vetor desordenado: ";
    printArray(arr5, n5);
    cout << "Verificação: " << (checkOrder(arr5, n5) ? "Correto" : "Incorreto") << endl
         << endl;

    int arr6[] = {1, 2, 4, 3, 5};
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    cout << "Vetor original: ";
    printArray(arr6, n6);
    mergeSort(arr6, 0, n6 - 1);
    cout << "Vetor com erro intencional: ";
    printArray(arr6, n6);
    cout << "Verificação: " << (checkOrder(arr6, n6) ? "Correto" : "Incorreto") << endl
         << endl;

    int arr7[] = {7, 2, 9, 1, 5};
    int n7 = sizeof(arr7) / sizeof(arr7[0]);
    cout << "Vetor original: ";
    printArray(arr7, n7);
    countingSort(arr7, n7);
    cout << "Counting Sort em vetor desordenado: ";
    printArray(arr7, n7);
    cout << "Verificação: " << (checkOrder(arr7, n7) ? "Correto" : "Incorreto") << endl
         << endl;

    int arr8[] = {4, 4, 4, 4, 4};
    int n8 = sizeof(arr8) / sizeof(arr8[0]);
    cout << "Vetor original: ";
    printArray(arr8, n8);
    selectionSort(arr8, n8);
    cout << "Selection Sort em vetor com elementos iguais: ";
    printArray(arr8, n8);
    cout << "Verificação: " << (checkOrder(arr8, n8) ? "Correto" : "Incorreto") << endl
         << endl;
}

int main()
{
    runTests();
    return 0;
}