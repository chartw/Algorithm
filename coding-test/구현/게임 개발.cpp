#include <iostream>

using namespace std;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int n, m, x, y, dir;

bool map[51][51];
bool d[51][51];

int main(){
    cin>>n>>m;
    cin>>x>>y>>dir;

    bool p;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>p;
            map[i][j]=p;
        }
    }
    int cnt=1;
    d[x][y]=1;
    for(;;){
        int i;
        int nx=-1, ny=-1;
        for(i=1;i<=4;i++){
            dir--;
            if(dir<0)dir+=4;
            nx=x+dx[dir];
            ny=y+dy[dir];
            if(map[nx][ny]==1 || d[nx][ny]==1) continue;
            if(nx<1 || nx>n-1 || ny<1 || ny>m-1) continue;
            d[nx][ny]=1;
            x=nx;
            y=ny;
            cnt++;
            break;
        }
        if(i==5){
            nx=x-dx[dir];
            ny=y-dy[dir];
            if(map[nx][ny]==1) break;
            if(nx<0 || nx>n-1 || ny<0 || ny>m-1) continue;
            x=nx;
            y=ny;
        }

    }
    cout<<cnt<<endl;
}