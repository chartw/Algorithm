#include <iostream>
#include <ctime>
#include <cmath>
#include "../algorithm.h"
using namespace std;

#define N 100000
int bigarr[N];
int bigarr1[N];

void ShellSort(int a[], int n, int flag)
{
    int h, i, j, v, k;
    int gap[1000];

    gap[0] = 1;
    k = 0;
    while (gap[k] < n)
    {
        k++;
        if (flag == 1)
            gap[k] = pow(4, k) + 3 * pow(2, k - 1) + 1;
        else
            gap[k] = (pow(3, k) - 1) / 2;
    }

    for (; k >= 0; k--)
    {
        for (i = gap[k]; i < n; i++)
        {
            v = a[i];
            j = i;
            while (j >= gap[k] && a[j - gap[k]] > v)
            {
                a[j] = a[j - gap[k]];
                j = j - gap[k];
            }
            a[j] = v;
        }
    }
}

int main()
{
    clock_t start, end;
    float res;
    int arr[10] = {10, 2, 8, 1, 6, 9, 4, 5, 3, 7};

    cout << "before Shell Sort\n";
    printArr(arr,10);

    ShellSort(arr,10,1);

    cout << "after Shell Sort\n\n";
    printArr(arr,10);

    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        bigarr[i] = rand() % N;
        bigarr1[i] = bigarr[i];
    }

    start = clock();
    ShellSort(bigarr, N,2);
    end = clock();
    res = (float)(end - start);
    checkSort(bigarr, N);

    cout << "Knuth Shell Sort running time = " << res << "ms\n\n";

    start = clock();
    ShellSort(bigarr1, N,1);
    end = clock();
    res = (float)(end - start);
    checkSort(bigarr1, N);

    cout << "Sedgewick Shell Sort running time = " << res << "ms\n";

    cout<<"\n12161800 ChaTaeWoong\n";

    system("pause");
}