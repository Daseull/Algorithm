/**
슬라이딩 윈도우 
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, vector<int>> MyPair;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<MyPair> tmp;
    
    int sum = sequence[0], len = sequence.size();
    
    for(int left = 0, right = 0; right < len;){
        if(left == right){
            if(sum == k)
                tmp.push_back({0, {left, right}});
            if(right < len - 1)
                sum += sequence[++right];
            else 
                break;
        }
        else if(sum == k){
            tmp.push_back({right - left, {left, right}});
            if(right < len - 1)
                sum += sequence[++right];
            else
                break;
        }
        else if(sum > k){
            sum -= sequence[left++];
        }
        else{ //sum < k
            if(right < len - 1)
                sum += sequence[++right];
            else break;
        }
        
        
        
    }
    
    sort(tmp.begin(), tmp.end());
    return tmp[0].second;
}
