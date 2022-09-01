#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> split(string sentence, char delimeter){
    vector<string> result;
    stringstream ss(sentence);
    string tmp;
    while(getline(ss, tmp, delimeter)){
        result.push_back(tmp);
    }
    return result;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    vector<pair<string, string>> msgs;
    map<string, string> m;
    map<string, string>::iterator it;
    
    for(auto& rec : record){
        vector<string> result = split(rec, ' ');
        if(result[0].compare("Enter") == 0){
            it = m.find(result[1]);
            if(it == m.end())
                m.insert({result[1], result[2]});
            it->second = result[2];
            msgs.push_back({result[1], "님이 들어왔습니다."});
        }
        else if(result[0].compare("Leave") == 0){
            msgs.push_back({result[1], "님이 나갔습니다."});
        }
        else {
            it = m.find(result[1]);
            it->second = result[2];
        }  
    }
    
    for(auto& msg : msgs){
        answer.push_back(m[msg.first] + msg.second);
    }
    
    return answer;
}