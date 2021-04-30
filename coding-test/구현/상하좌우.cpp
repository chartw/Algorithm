#include <iostream>
#include <vector>

using namespace std;

int n;
int x = 1;
int y = 1;
string plans;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
char d[4]={'L','R','U','D'};

int main(){    
    cin >>n;

    cin.ignore();
    getline(cin,plans); // 공백으로 구분하여 plans[i]로 되는듯?

    for(int i=0;i<plans.size();i++)
    {
        int nx=-1;
        int ny=-1;
        for(int j=0;j<4;j++){
            if(plans[i]==d[j]){
                nx=x+dx[j];
                ny=y+dy[j];
            }
        }
        if(nx<1 || nx>n || ny<1 || ny>n) continue;

        x=nx;
        y=ny;
    }

    cout<<x<<" "<<y;
}
