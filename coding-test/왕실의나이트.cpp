#include <iostream>

using namespace std;

string pos;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int main(){
    cin>>pos;

    int x=pos[0]-96;
    int y=pos[1]-48;
    int cnt=0;
    for(int i=0;i<4;i++){
        int nx=-1, ny=-1;

        nx=x+2*dx[i];
        ny=y+2*dy[i];
        if(nx<1 || nx>8 || ny<1 || ny>8) continue;
        for(int j=0;j<2;j++){
            if(i==0 || i==1) nx=x+dx[j+2];
            else ny=y+dy[j];
            if(nx<1 || nx>8 || ny<1 || ny>8) continue;
            cnt++;
        }
    }
    cout<<cnt<<endl;
}

// 모범 답안
// #include <iostream>

// using namespace std;

// string pos;

// int dx[8]={-2,-2,2,2,-1,1,-1,1};
// int dy[8]={-1,1,-1,1,-2,-2,2,2};

// int main(){
//     cin>>pos;

//     int x=pos[0]-96;
//     int y=pos[1]-48;
//     int cnt=0;
//     for(int i=0;i<8;i++){
//         int nx=-1, ny=-1;

//         nx=x+dx[i];
//         ny=y+dy[i];
//         if(nx<1 || nx>8 || ny<1 || ny>8) continue;

//         cnt++;
//     }
//     cout<<cnt<<endl;
// }