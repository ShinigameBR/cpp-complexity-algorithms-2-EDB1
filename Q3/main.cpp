#include <iostream>
using namespace std;

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

    selectionSort(arr, n);
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