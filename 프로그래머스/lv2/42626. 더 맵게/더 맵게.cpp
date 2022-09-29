#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto& s : scoville)
        pq.push(s);
    while(pq.top() < K){
        if(pq.size() == 1)
            return -1;
        int a, b;
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();       
        pq.push(a + 2 * b);
        answer++; 
    }
    
    return answer;
}