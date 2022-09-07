#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

vector<string> reportNames(string s){
    vector<string> ret;
    int n = s.find(' ');

    ret.push_back(s.substr(0, n));
    ret.push_back(s.substr(n+1));
    return ret;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int size = int(id_list.size());
    
    vector<int> answer(size, 0);
    map<string,int> m;
    vector<set<string>> reported(size);
    
    for(int i=0;i<size;i++)
        m.insert({id_list[i], i});
    
    for(auto& r : report){
        vector<string> names = reportNames(r);
        reported[m[names[1]]].insert(names[0]);    
    }
    
    for(int i=0;i<size;i++){
        if(reported[i].size() < k)
            continue;
        for(auto& reciver : reported[i]){
            answer[m[reciver]]++;
        }
    }
    

    return answer;
}