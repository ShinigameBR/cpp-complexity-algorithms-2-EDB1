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

    cout << "Resultado: " << (checkOrder(arr, n) ? "true" : "false") << endl;

    return 0;
}