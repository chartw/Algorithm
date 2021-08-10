#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <unordered_map>

using namespace std;

stack<int> pos;
stack<int> val;


string solution(int n, int k, vector<string> cmd) {
    int h=n;
    string answer = "";
    vector<pair<int,char>> t;
    for(int i=0;i<n;i++){
        t.push_back({i,'O'});
    }
    //    for(int i=0;i<t.size();i++){
    //     cout<<t[i].first;

    // }
    
    for(int i=0;i<cmd.size();i++){
        if(cmd[i][0]=='U'){
            k-=cmd[i][2]-48;

        }
        else if(cmd[i][0]=='D'){
            k+=cmd[i][2]-48;
        }
        else if(cmd[i][0]=='C'){
            val.push(t[k].first);
            t.erase(t.begin()+k);
            pos.push(k);
            cout<<k<<endl;
            for(int i=0;i<t.size();i++){
                cout<<t[i].first;

            }
            cout<<endl;
            if(k==n-1) k--;
            n--;
        }
        else if(cmd[i][0]=='Z'){
            int temp=pos.top();
            int tempval=val.top();
            
            if(k==n-1){
                n++;
                k++;
            }
            t.insert(t.begin()+temp,{tempval,'O'});
            for(int i=0;i<t.size();i++){
                cout<<t[i].first;

            }
            cout<<endl;
            cout<<temp<<endl;;
            
            pos.pop();
            val.pop();
        }
    }
    int cnt=0;
    for(int i=0;i<h;i++){
        if(t[cnt].first==i){
            answer+="O";
            cnt++;
        }
        else {
            answer+="X";
        }
    }
    return answer;
}

int main(){
    int n=8;
    int k=2;
    vector<string> cmd={"D 2","C","U 3","C","D 4","C","U 2","Z","Z"};

    string res=solution(n,k,cmd);
    cout<<res<<endl;
}