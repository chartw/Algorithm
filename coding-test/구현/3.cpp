#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> ads) {
    int answer = 0;
    sort(ads.begin(),ads.end());
    int endt=ads[ads.size()-1][0]+5;
    int adidx=0;
    int ad_st=ads[0][0];
    int ad_end=ad_st+5;
    bool comad[ads.size()]={0};
    int min=9999999;
    for(int i=0;i<ads.size();i++){
        if(comad[i]==0){
            ads[i]
        }
    }
    if(ads[adidx][1]*)
    for(int t=0;t<endt;t++){
        if(t==ad_end){
            adidx++;
            if(ad_st>t) ad_st=ads[adidx][0];
            else ad_st=t;
            ad_end=ad_st+5;
        }
        if(ad_st>t) continue;
        for(int i=adidx+1;i<ads.size();i++){
            if(ads[i][0]<=t) answer+=ads[i][1];
        }

    }
    return answer;
}

int main(){
    vector<vector<int>> ads={{1,3},{3,2},{5,4}};
    cout<<ads[0][0]<<ads[0][1]<<endl;
    cout<<solution(ads)<<endl;
}