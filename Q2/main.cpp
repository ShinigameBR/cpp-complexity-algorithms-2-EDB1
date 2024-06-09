#include <iostream>
using namespace std;

bool verificar_ordem_crescente(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cout << "Digite o tamanho do vetor:" << endl;
    int n;
    cin >> n;

    int a[n];
    cout << "Digite os items do vetor:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Item " << i << ": ";
        cin >> a[i];
    }

    cout << "Resultado: " << (verificar_ordem_crescente(a, n) ? "true" : "false") << endl;

    return 0;
}