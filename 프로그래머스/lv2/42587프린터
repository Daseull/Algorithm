/**
* https://school.programmers.co.kr/learn/courses/30/lessons/42587
*/

#include <string>
#include <vector>
#include <queue> 
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0, n = priorities.size();
    queue<pair<int,int>> q;
    
    for(int i=0;i<n;i++){
        q.push({priorities[i], i});
    }
    sort(priorities.begin(), priorities.end(), greater<>());    
    while(!q.empty()){
        if(q.front().first == priorities[answer]){
            answer++;
            if(q.front().second == location)
                return answer;
            q.pop();
        }
        else{
            q.push(q.front());
            q.pop();
        }
    }
    return answer;
}
