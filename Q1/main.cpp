#include <ctime> // Para time()
#include <iostream>
#include <stdlib.h> // Para rand() e srand()
using namespace std;

int *generateRandomArray(int N)
{
    // Usar o tempo atual como semente para o gerador
    srand(time(nullptr));

    int *randomArray = new int[N];

    // Gerar valores aleatórios e adicionar ao array
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