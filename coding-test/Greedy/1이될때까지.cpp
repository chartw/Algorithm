#include <iostream>
#include <algorithm>
using namespace std;
int n, k;

int main(){
    cin>>n>>k;

    int cnt;
    while(n!=1){
        if(n%k!=0)
            n--;
        else
            n/=k;
        cnt++;
    }
    cout<<cnt;
}