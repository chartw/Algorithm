#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int test_cases;
void Set() {

	ifstream infile;
	infile.open("sample_input.txt");
    infile >> test_cases;
    
}

int main() {
    ifstream infile;
	infile.open("sample_input.txt");
    infile >> test_cases;
    
    for (int i=0;i<test_cases;i++){
        int camel_num;
        infile >> camel_num;
        
        vector <int> cost;
        for(int c=0;c<camel_num;c++)
        {
            int temp;
            infile >> temp;
            cost.push_back(temp);
        }

        for(int c=0;c<camel_num;c++){
            cout<<cost[c];
        }
        
        
    }
    return 0;
}