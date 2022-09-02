#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    answer.push_back(arr[0]);
    for(auto& e : arr){
        if(answer.back() != e)
            answer.push_back(e);
    }
    return answer;
}