#include <iostream>
#include <vector>

using namespace std;

#define I 100

void printArr(vector<vector<int>> v, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for(int j=1;j<=n;j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}

void floyd2(int n, vector <vector<int>> &w, vector <vector<int>> &d, vector <vector<int>> &p){
    vector<vector<int>> t(6, vector<int>(6, 0));
    p=t;    //p 배열 0으로 초기화
    d=w;    //d 배열 w로 초기화

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(d[i][k]+d[k][j] < d[i][j]){      //k를 거쳐간 경로의 비용이 더 적을 경우
                    p[i][j]=k;                      //지나친 정점 인덱스 path에 업데이트
                    d[i][j]=d[i][k]+d[k][j];        //k를 거쳐간 경로 비용으로 업데이트
                }
            }
        }
    }
}

void path(vector<vector<int>> p, int q, int r){
    if(p[q][r]!=0){
        path(p, q, p[q][r]);        // 왼쪽. q와 p[q][r]의 사이
        cout<<" v"<<p[q][r]<<" ->";
        path(p, p[q][r], r);        // 오른쪽. p[q][r]과 r의 사이
    }
}

int main(){
    vector <vector<int>> w={{0, 0, 0, 0, 0, 0},
                            {0, 0, 1, I, 1, 5},
                            {0, 9, 0, 3, 2, I},
                            {0, I, I, 0, 4, I},
                            {0, I, I, 2, 0, 3},
                            {0, 3, I, I, I, 0}};
    vector<vector<int>> d;
    vector<vector<int>> p;
    floyd2(5, w, d, p);

    // cout<<d[0][0]<<endl;

    cout<<"D[i][j] is\n";
	printArr(d, 5);
    cout<<"\nP[i][j] is\n";
	printArr(p, 5);
    cout<<"\nThe shortest path(2,5) is v2 ->";
    path(p,2,5);
    cout<<" v5\n\n";

    cout<<"D[i][j] is\n";
	printArr(d, 5);
    cout<<"\nP[i][j] is\n";
	printArr(p, 5);
    cout<<"\nThe shortest path(5,3) is v5 ->";
    path(p,5,3);
    cout<<" v3\n\n";

    cout<<"D[i][j] is\n";
	printArr(d, 5);
    cout<<"\nP[i][j] is\n";
	printArr(p, 5);
    cout<<"\nThe shortest path(1,3) is v1 ->";
    path(p,1,3);
    cout<<" v3\n\n";
	
}