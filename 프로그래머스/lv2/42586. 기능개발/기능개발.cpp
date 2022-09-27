#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> deploy;
    
    for(int i=0;i<progresses.size();i++){
        int d = ceil(1.0 * (100 - progresses[i]) / speeds[i]);
        deploy.push(d);
    }
    
    int day = 1;
    while(!deploy.empty()){
        int cnt = 0;
        while(!deploy.empty() && deploy.front() <= day){
            cnt++;
            deploy.pop();
        }
        if(cnt > 0)
            answer.push_back(cnt);
        day++;
    }
    
    
    return answer;
}