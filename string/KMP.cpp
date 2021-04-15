#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void InitNext(char p[], int M, int next[])
{
    next[0] = -1;
    for (int i = 0, j = -1; i < M; i++, j++)
    {
        if (p[i] == p[j])
            next[i] = next[j];
        else next[i] = j;
        while ((j >= 0) && p[i]!=p[j])
        {
            j = next[j];
        }
    }
}

int main()
{
    char text1[5] = {'A', 'A', 'B', 'A', 'A'};
    char text2[7] = {'A', 'B', 'A', 'A', 'B', 'A', 'B'};
    char text3[8] = {'A', 'B', 'A', 'B', 'A', 'B', 'A', 'C'};

    int next1[5];
    int next2[7];
    int next3[8];

    InitNext(text1, 5, next1);
    InitNext(text2, 7, next2);
    InitNext(text3, 8, next3);

    printArr(next1, 5);
    printArr(next2, 7);
    printArr(next3,8);
}