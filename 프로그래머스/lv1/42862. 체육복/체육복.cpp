#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    vector<int>::iterator it;
    for(int i=0;i<lost.size();i++){
        it = find(reserve.begin(), reserve.end(), lost[i]);
        if(it != reserve.end()){
            lost[i] = 0;
            *it = 0;
        }
    }
    
    for(int i=0;i<lost.size();i++){
        if(lost[i] == 0)
            continue;
        if(lost[i] != 1){
            it = find(reserve.begin(), reserve.end(), lost[i] - 1);
            if(it != reserve.end()){
                *it = 0;
                continue;
            }
        }
        it = find(reserve.begin(), reserve.end(), lost[i] + 1);
        if(it != reserve.end())
            *it = 0;
        else
            n--;
    }
    
    
    
    
    
    
    return n;
}