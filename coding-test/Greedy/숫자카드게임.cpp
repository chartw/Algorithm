#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int a[101][101];

int main(){
    cin>>n>>m;
    int num;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>num;
            a[i][j]=num;
        }
    }

    int minmax=0;
    for(int i=0;i<n;i++){
        sort(a[i],a[i]+m);
        if(minmax<a[i][0])
            minmax=a[i][0];
    }

    cout<<minmax;
}