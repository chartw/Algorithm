#include <iostream>

using namespace std;

int n;

int main(){
    cin>>n;

    int cnt=0;

    for(int h=0;h<=n;h++){
        for(int m=0;m<60;m++){
            for(int s=0;s<60;s++){
                if(s/10==3 || m/10==3 || s%10==3 || m%10==3 || h%10==3) cnt++;
            }
        }
    }

    cout<<cnt<<endl;

}