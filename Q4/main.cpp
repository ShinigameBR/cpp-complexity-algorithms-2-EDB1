#include <iostream>
using namespace std;

void merge(int arr[], int beginArray[], int beginSize, int endArray[], int endSize)
{
    int i = 0, j = 0, k = 0;
    while (i < beginSize && j < endSize)
    {
        if (beginArray[i] <= endArray[j])
        {
            arr[k++] = beginArray[i++];
        }
        else
        {
            arr[k++] = endArray[j++];
        }
    }
    while (i < beginSize)
    {
        arr[k++] = beginArray[i++];
    }
    while (j < endSize)
    {
        arr[k++] = endArray[j++];
    }
}

void mergeSort(int arr[], int const begin, int const end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    int beginArray[mid - begin + 1], endArray[end - mid];
    for (int i = 0; i <= mid - begin; i++)
    {
        beginArray[i] = arr[begin + i];
    }
    for (int i = 0; i < end - mid; i++)
    {
        endArray[i] = arr[mid + 1 + i];
    }
    merge(arr, beginArray, mid - begin + 1, endArray, end - mid);
}

int main()
{
    cout << "Digite o tamanho do array:" << endl;
    int n;
    cin >> n;

    int arr[n];
    cout << "Digite os items do array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Item " << i << ": ";
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);
    cout << "Array gerado: [";
    for (int i = 0; i < n; ++i)
    {
        if (i < n - 1)
        {
            cout << arr[i] << ", ";
        }
        else
        {
            cout << arr[i] << "]" << endl;
        }
    }
    return 0;
}