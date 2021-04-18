#include <iostream>
using namespace std;

#include <cuda_runtime.h>       
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define THREADS pow(2,8)// 256
#define BLOCKS pow(2,13)
#define NUM_VALS THREADS*BLOCKS     //정렬할 원소 개수

int* dynamic_alloc(int n)
{
    int* arr = new int[n];
    return arr;
}

void delete_alloc(int** arr, int n)
{
    for (int j = 0; j < n; j++)
    {
        delete[] arr[j];
    }
    delete[] arr;
}

void print_rt(clock_t start, clock_t stop)
{
    double time = ((double)(stop - start)) / CLOCKS_PER_SEC;
    printf("Run time: %.3fs\n", time);
}


__global__ void bitonic_sort_step(int* dev_values, int j, int k)
{
    unsigned int i, ixj; /* Sorting partners: i and ixj */
    i = threadIdx.x + blockDim.x * blockIdx.x;// thread 인덱싱

    ixj = i ^ j;

    /* The threads with the lowest ids sort the array. */
    if ((ixj) > i) {
        if ((i & k) == 0) {
            /* Sort ascending */
            if (dev_values[i] > dev_values[ixj]) {
                /* exchange(i,ixj); */
                int temp = dev_values[i];
                dev_values[i] = dev_values[ixj];
                dev_values[ixj] = temp;
            }
        }
        if ((i & k) != 0) {
            /* Sort descending */
            if (dev_values[i] < dev_values[ixj]) {
                /* exchange(i,ixj); */
                int temp = dev_values[i];
                dev_values[i] = dev_values[ixj];
                dev_values[ixj] = temp;
            }
        }
    }
}

void bitonic_sort(int* values)
{
    int* dev_values;
    size_t size = NUM_VALS * sizeof(int);

    cudaMalloc((void**)&dev_values, size);                      //쿠다 메모리 할당
    cudaMemcpy(dev_values, values, size, cudaMemcpyHostToDevice);//정렬할 배열을 dev_values에 복사

    // Block과 Thread는 1차원
    dim3 blocks(BLOCKS, 1);    /* Number of blocks   */
    dim3 threads(THREADS, 1);  /* Number of threads  */

    int j, k;
    /* Major step */
    for (k = 2; k <= NUM_VALS; k <<= 1) {
        /* Minor step */
        for (j = k >> 1; j > 0; j = j >> 1) {
            bitonic_sort_step << <blocks, threads >> > (dev_values, j, k);  //dev_values 배열 정렬
            //1 block당 threads가 할당됨 즉 전체 thread 개수는 blocks*threads
        }
    }
    cudaMemcpy(values, dev_values, size, cudaMemcpyDeviceToHost);           //정렬 완료된 배열을 values에 저장
    cudaFree(dev_values);                   //메모리 해제
}

void _swap(int arr[], int a, int b)
{
    int temp = arr[b];
    arr[b] = arr[a];
    arr[a] = temp;
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
    if (r - l <= n)     //배열의 크기가 n보다 작거나 같을시, 삽입정렬 수행
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
        _swap(a, i, r - 1);     //피벗 값을 좌측 부분과 우측 부분 사이로 이동
        ThreeMedianInsertQS(a, l, i - 1, n); //좌측 부분 재귀 호출
        ThreeMedianInsertQS(a, i + 1, r, n); //우측 부분 재귀 호출
    }
    else if (a[l] > a[r]) //배열의 크기가 2보다 작을 때, 좌측 값이 우측 값보다 크면
        _swap(a, l, r);   //두 값 swap
}

// v : 삽입 정렬 key값 / k : gap sequence index
void ShellSort(int a[], int n)
{
    int i, j, v, k;
    int gap[20];

    gap[0] = 1;     //gap sequence 초항은 1
    k = 0;

    while (gap[k] < n) {
        k++;
        gap[k] = pow(4, k) + 3 * pow(2, k - 1) + 1;//Sedgewick gap sequence
    }

    for (; k >= 0; k--) {
        for (i = gap[k]; i < n; i++) {      //gap만큼 점프하며 삽입 정렬
            v = a[i];
            j = i;
            while (j >= gap[k] && a[j - gap[k]] > v) {
                a[j] = a[j - gap[k]];
                j = j - gap[k];
            }
            a[j] = v;
        }
    }
}


// sorting이 정순으로 되었는지 check
void checkSort(int a[], int n)
{
    int i, sorted;
    sorted = true;
    for (i = 0; i < n - 1; i++)
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


int main(void) {
    clock_t start, stop;
    int* a1 = dynamic_alloc(NUM_VALS);
    int* a2 = dynamic_alloc(NUM_VALS);
    int* a3 = dynamic_alloc(NUM_VALS);

    cout << "Number of Values : " << NUM_VALS << "\n";

    srand(time(NULL));
    for (int i = 0; i < NUM_VALS; i++)
    {
        a1[i] = rand() % RAND_MAX;
        a2[i] = a1[i];
        a3[i] = a1[i];
    }
    start = clock();
    bitonic_sort(a1);
    stop = clock();
    checkSort(a1, NUM_VALS);
    cout << "Bitonic_cuda ";
    print_rt(start, stop);

    start = clock();
    ThreeMedianInsertQS(a2, 0, NUM_VALS - 1, 15);
    stop = clock();
    checkSort(a2, NUM_VALS);
    cout << "Quick ";
    print_rt(start, stop);

    start = clock();
    ShellSort(a3, NUM_VALS);
    stop = clock();
    checkSort(a3, NUM_VALS);
    cout << "Shell ";
    print_rt(start, stop);

}