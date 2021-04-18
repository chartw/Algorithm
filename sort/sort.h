#pragma once
#include <iostream>
#include <ctime>
using namespace std;

// arr 출력
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void checkSort(int a[], int n)
{
    int i, sorted;
    sorted = true;
    for (i = 0; i < n-1; i++)
    {
        if (a[i] > a[i + 1])
        {
            sorted = false;
        }
        if (!sorted)
        {
            break;
        }
    }
    if (sorted)
    {
        cout << "Sorting complete!" << endl;
    }
    else
    {
        cout << "Error during sorting..." << endl;
    }
}

// swap
void _swap(int arr[], int a, int b)
{
    int temp = arr[b];
    arr[b] = arr[a];
    arr[a] = temp;
}