#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

pair<int,int> start_end(string s){
    int start, end;
    int H, M;
    int E, T;
    s.pop_back();
    H = stoi(s.substr(11, 2));
    M = stoi(s.substr(14, 2));
    E = 1000.0 * stod(s.substr(17, 6));
    T = 1000.0 * stod(s.substr(24));
    
    start = H * 3600000 + M * 60000 + E - T + 1;
    end = H * 3600000 + M * 60000 + E;
    start = max(0, start);
    return make_pair(start, end);
}

int solution(vector<string> lines) {
    int answer = 1;
    vector<pair<int,int>> v;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(auto& line: lines){
        v.push_back(start_end(line));
    }
    sort(v.begin(), v.end());
    
    for(int i=0;i<v.size();i++){
        if(pq.empty()){
            pq.push(v[i].second);
        }
        else{
            while(!pq.empty() && (pq.top() + 999 < v[i].first)){
                pq.pop();
            }
            pq.push(v[i].second);
            answer = max(answer, int(pq.size()));
        }
    }
    return answer;
}