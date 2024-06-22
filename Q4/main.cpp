#include <iostream>
using namespace std;

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