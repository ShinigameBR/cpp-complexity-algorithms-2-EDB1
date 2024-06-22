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

int main()
{
    int N;
    cout << "Digite o tamanho do array: ";
    cin >> N;

    int *randomArray = generateRandomArray(N);

    cout << "Array gerado: [";
    for (int i = 0; i < N; ++i)
    {
        if (i < N - 1)
        {
            cout << randomArray[i] << ", ";
        }
        else
        {
            cout << randomArray[i] << "]" << endl;
        }
    }

    delete[] randomArray;

    return 0;
}