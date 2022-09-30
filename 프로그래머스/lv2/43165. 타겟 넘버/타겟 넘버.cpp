#include <string>
#include <vector>

using namespace std;

int recur(vector<int> numbers, int target, int sum, int idx, int rest){
    if(idx == numbers.size())
        return sum == target;
    
    int ret = 0;
    rest -= numbers[idx];
    // if(sum + numbers[idx] - rest > target) 
    //     return 0;
    ret += recur(numbers, target, sum + numbers[idx], idx+1, rest);
    // if(sum - numbers[idx] + rest < target)
    //     return ret;
    ret += recur(numbers, target, sum - numbers[idx], idx+1, rest);
    return ret;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    int rest = 0;
    for(auto& num : numbers)
        rest += num;
    return recur(numbers, target, 0, 0, rest);
    
    return answer;
}