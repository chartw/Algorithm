#include <iostream>
#include <ctime>
#include "sort.h"
using namespace std;

#define N 100000000
int bigarr[N];
int bigarr1[N];

//Quick Sort - a : 배열 / l : 시작 인덱스 / r : 끝 인덱스
void ThreeMedianQS(int a[], int l, int r)
{
    int i, j, m, v;
    if (r - l > 1) //배열의 크기가 2보다 크면
    {
        m = (l + r) / 2; //중간 인덱스값 m

        //중간값을 이용하여 성능 향상
        //a[l], a[m], a[r] 값중 중간값이 m 인덱스에 가도록 swap
        if (a[l] > a[m])
            _swap(a, l, m);
        if (a[l] > a[r])
            _swap(a, l, r);
        if (a[m] > a[r])
            _swap(a, m, r);

        _swap(a, m, r - 1); //중간값 a[m]을 가장 끝 인덱스 r 로 이동
        v = a[r - 1];       //피벗 값
        i = l;              //left 포인터
        j = r - 1;          //right 포인터

        //피벗값을 기준으로 좌측 부분(피벗보다 작은 값), 우측 부분(피벗보다 큰 값)으로 분할
        for (;;)
        {
            while (a[++i] < v)
                ; //left 포인터가 가리키는 값이 피벗보다 작으면 포인터 우측 이동
            while (a[--j] > v)
                ; //right 포인터가 가리키는 값이 피벗보다 크면 포인터 좌측 이동
            if (i >= j)
                break; //left 포인터와 right 포인터가 교차하면, 반복문 탈출

            //left 포인터가 가리키는 값이 피벗보다 크거나, right 포인터가 가리키는 값이 피벗보다 작으면
            //if(a[i] > v || a[j] < v)
            _swap(a, i, j); //두 값 swap
        }
        _swap(a, i, r - 1);         //피벗 값을 좌측 부분과 우측 부분 사이로 이동
        ThreeMedianQS(a, l, i - 1); //좌측 부분 재귀 호출
        ThreeMedianQS(a, i + 1, r); //우측 부분 재귀 호출
    }
    else if (a[l] > a[r]) //배열의 크기가 2보다 작을 때, 좌측 값이 우측 값보다 크면
        _swap(a, l, r);   //두 값 swap
}

void InsertSort(int a[], int l, int r)
{
    int i, j, temp;
    for (i = l + 1; i <= r; i++)
    {
        temp = a[i];
        for (j = i - 1; j >= l && a[j] > temp; j--)
            a[j + 1] = a[j];
        a[j + 1] = temp;
    }
}

//Quick Sort - a : 배열 / l : 시작 인덱스 / r : 끝 인덱스
void ThreeMedianInsertQS(int a[], int l, int r, int n)
{
    int i, j, m, v;
    if (r - l <= n)
        InsertSort(a, l, r);
    else if (r - l > 1) //배열의 크기가 2보다 크면
    {
        m = (l + r) / 2; //중간 인덱스값 m

        //중간값을 이용하여 성능 향상
        //a[l], a[m], a[r] 값중 중간값이 m 인덱스에 가도록 swap
        if (a[l] > a[m])
            _swap(a, l, m);
        if (a[l] > a[r])
            _swap(a, l, r);
        if (a[m] > a[r])
            _swap(a, m, r);

        _swap(a, m, r - 1); //중간값 a[m]을 가장 끝 인덱스 r 로 이동
        v = a[r - 1];       //피벗 값
        i = l;              //left 포인터
        j = r - 1;          //right 포인터

        //피벗값을 기준으로 좌측 부분(피벗보다 작은 값), 우측 부분(피벗보다 큰 값)으로 분할
        for (;;)
        {
            while (a[++i] < v)
                ; //left 포인터가 가리키는 값이 피벗보다 작으면 포인터 우측 이동
            while (a[--j] > v)
                ; //right 포인터가 가리키는 값이 피벗보다 크면 포인터 좌측 이동
            if (i >= j)
                break; //left 포인터와 right 포인터가 교차하면, 반복문 탈출

            //left 포인터가 가리키는 값이 피벗보다 크거나, right 포인터가 가리키는 값이 피벗보다 작으면
            //if(a[i] > v || a[j] < v)
            _swap(a, i, j); //두 값 swap
        }
        _swap(a, i, r - 1);                  //피벗 값을 좌측 부분과 우측 부분 사이로 이동
        ThreeMedianInsertQS(a, l, i - 1, n); //좌측 부분 재귀 호출
        ThreeMedianInsertQS(a, i + 1, r, n); //우측 부분 재귀 호출
    }
    else if (a[l] > a[r]) //배열의 크기가 2보다 작을 때, 좌측 값이 우측 값보다 크면
        _swap(a, l, r);   //두 값 swap
}

int main()
{
    clock_t start, end;
    float res;
    int arr[10] = {10, 2, 8, 1, 6, 9, 4, 5, 3, 7};

    cout << "before Quick Sorting\n";
    printArr(arr, 10);

    ThreeMedianQS(arr, 0, N - 1);

    cout << "after Quick Sorting\n";
    printArr(arr, 10);

    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        bigarr[i] = rand() % N;
        bigarr1[i] = bigarr[i];
    }

    start = clock();
    ThreeMedianQS(bigarr, 0, N - 1);
    end = clock();
    res = (float)(end - start);
    cout << "\ncheck Three Median Quick sort\n";
    checkSort(bigarr, N);

    cout << "Three Median running time = " << res << "ms\n";

    start = clock();
    ThreeMedianInsertQS(bigarr1, 0, N - 1, 15);
    end = clock();
    res = (float)(end - start);
    cout << "\ncheck Three Median Insertion Quick sort\n";
    checkSort(bigarr1, N);

    cout << "Three Median Insertion running time = " << res << "ms\n";

    cout << "12161800 ChaTaeWoong\n";
}