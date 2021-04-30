#include <iostream>
#include <algorithm>
using namespace std;
int n, m, k;
int a[1001];

int main(){
    cin>> n>> m>>k;

    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        a[i]=num;
    }

    sort(a,a+n);

    int max1=a[n-1];
    int max2=a[n-2];

    int maxmul=m/k;
    int res=maxmul*k*max1+(m-maxmul*k)*max2;

    cout<<res<<endl;
}