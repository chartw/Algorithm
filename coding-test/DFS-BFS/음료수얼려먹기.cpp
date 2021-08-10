#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
bool a[1001][1001];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int cnt;

bool dfs(int x, int y){

    if(x<0 || x>n-1 || y<0 || y>m-1) return 0;
    
    if(a[x][y]==1){
        a[x][y]=1;
        dfs(x-1,y);
        dfs(x+1,y);
        dfs(x,y-1);
        dfs(x,y+1);
        return 1;
    }
    else return 0;

}

int main(){
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d", &a[i][j]); // 공백없이 한글자씩 입력받고싶은 경우
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dfs(i,j) == 1) cnt++;
        }
    }

    cout<<cnt;
}