#include <iostream>
using namespace std;

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

    countingSort(arr, n);
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