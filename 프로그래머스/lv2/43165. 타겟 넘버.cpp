/**
완전탐색 
*/

#include <string>
#include <vector>
#include <cstring>

using namespace std;


int recur(vector<int>& numbers, int idx, int rest){
    if(idx == numbers.size()){
        return rest == 0;
    }
    
    return recur(numbers, idx+1, rest-numbers[idx]) +  recur(numbers, idx+1, rest+numbers[idx]);
    
}


int solution(vector<int> numbers, int target) {
    int answer = 0;
    return recur(numbers, 0, target);
}
