#include <iostream>
#include <algorithm>
using namespace std;
auto n=0, k=0;

int main(){
    cin>>n>>k;

    auto cnt=0;
    while(n!=1){
        if(n%k!=0)
            n--;
        else
            n/=k;
        cnt++;
    }
    cout<<cnt;
}