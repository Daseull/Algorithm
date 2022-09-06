#include <string>
#include <vector>
#include <map>

using namespace std;

int match(string s, int& offset){
    vector<vector<string>> word = {{"one", "two", "six"},
                                   {"zero", "four", "five", "nine"},
                                   {"three", "seven", "eight"}};
    map<string, int> m = {{"zero", 0}, {"one", 1},{"two", 2},{"three", 3},{"four", 4},
                         {"five", 5},{"six", 6},{"seven", 7},{"eight", 8},{"nine", 9}};
    
    for(int i=0;i<3;i++){
        string tmp = s.substr(offset, 3+i);
        for(auto& w : word[i]){
            if(tmp.compare(w) == 0){
                offset += 3+i;
                return m[w];
            }
        }
    }
    return 0;
}

int solution(string s) {
    int answer = 0;
    string result = "";
    for(int i=0;i<s.length();){
        if(s[i]>='0' && s[i]<='9'){
            result.push_back(s[i]);
            i++;
        }    
        else{
            result.push_back(match(s, i) + '0');
        }
    }
    answer = stoi(result);
    return answer;
}