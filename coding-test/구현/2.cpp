#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;
    vector<int> hash(100001,999999);
    for(int i=0;i<array.size();i++)
    {
        if(hash[i%100000]==999999)
            hash[i%100000]=array[i];
        else{
            int p=i%100000+1;
            while(hash[p]!=999999){
                p++;
                if(p>=100000) p-=100000;
            }
            hash[i%100000]=array[i];
        }
    }
    return answer;
}