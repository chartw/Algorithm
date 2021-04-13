#include <iostream>
#include <ctime>
#include "../algorithm.h"
using namespace std;

#define N 100000
int bigarr[N];

void InsertionSort(int a[], int l, int r)
{
    int i, j, temp;
    for (i = l+1; i <= r; i++)
    {
        temp = a[i];
        for (j = i - 1; j >= l && a[j] > temp; j--)
            a[j + 1] = a[j];
        a[j + 1] = temp;
    }
}

int main()
{
    clock_t start, end;
    float res;
    int arr[10] = {10, 2, 8, 1, 6, 9, 4, 5, 3, 7};

    cout << "before Insertion Sort\n";
    printArr(arr,10);

    InsertionSort(arr,0,10-1);

    cout << "after Insertion Sort\n";
    printArr(arr,10);

    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        bigarr[i] = rand() % N;
    }

    start = clock();
    InsertionSort(bigarr, 0, N-1);
    end = clock();
    res = (float)(end - start);
    cout << "\ncheck Insertion sort\n";
    checkSort(bigarr, N);

    cout << "InsertionSort running time = " << res << "ms\n";

    cout<<"\n12161800 ChaTaeWoong\n";
    system("pause");
}