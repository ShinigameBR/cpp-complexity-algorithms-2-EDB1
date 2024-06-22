#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const int numSizes = 5;
    const int numAlgorithms = 3;

    int sizes[numSizes] = {100, 1000, 10000, 100000, 500000};

    // Tempos de execução em segundos
    double selectionSortTimes[numSizes] = {4.3e-05, 0.00315, 0.259792, 26.283, 676.447};
    double mergeSortTimes[numSizes] = {2e-05, 0.000228, 0.003027, 0.03737, 0.208303};
    double countingSortTimes[numSizes] = {8e-06, 3.9e-05, 0.000395, 0.004114, 0.02225};

    cout << setw(15) << "Tamanho do Vetor"
         << setw(20) << "Selection Sort (s)"
         << setw(18) << "Merge Sort (s)"
         << setw(20) << "Counting Sort (s)"
         << endl;

    for (int i = 0; i < numSizes; ++i)
    {
        cout << setw(15) << sizes[i]
             << setw(20) << selectionSortTimes[i]
             << setw(18) << mergeSortTimes[i]
             << setw(20) << countingSortTimes[i]
             << endl;
    }

    return 0;
}
