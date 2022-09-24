#include <string>
#include <vector>
#include <set>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    vector<vector<string>> ls(20, vector<string>());
    for(auto& phone : phone_book){
        ls[int(phone.length()) - 1].push_back(phone);
    }
    
    set<string> s;
    for(int i=0;i<20;i++){
        for(auto& phone : ls[i]){
            for(int j=1;j<phone.length();j++){
                if(s.find(phone.substr(0, j))!=s.end()){
                    return answer = false;
                }
            } 
            s.insert(phone);
        }
    }
    
    
    return answer;
}