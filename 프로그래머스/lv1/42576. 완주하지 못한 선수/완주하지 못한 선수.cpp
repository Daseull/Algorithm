#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> m;
    for(auto& p : participant){
        if(m.find(p) != m.end())
            m[p]++;
        else
            m.insert({p, 1});
    }
    
    for(auto& c : completion)
        m[c]--;
    
    for(auto iter = m.begin(); iter != m.end(); iter++){
        if(iter->second == 1)
            return iter->first;
    }
    
    
    
    
    
    
    return answer;
}