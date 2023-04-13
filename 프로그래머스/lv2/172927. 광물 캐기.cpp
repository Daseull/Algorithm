/**
5개 <-> 가치가 5의 제곱수 
그리디 이용 
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;


bool cmp(vector<int> a, vector<int> b){
    if(a[0] > b[0])
        return true;
    if(a[0] == b[0]){
        if(a[1] > b[1])
            return true;
        if(a[1] == b[1] && a[2]>b[2])
            return true;
    }
    return false;
}


int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    vector<vector<int>> count; //{{d, i, s}, ...} 
    
    int tool = 0;
    for(int& p : picks)
        tool += p;
    
    int row = min((int)minerals.size() / 5 + 1, tool);
    for(int i=0; i < row; i++){
        vector<int> tmp = {0,0,0};
        for(int j=0; j < 5 && i * 5 + j < minerals.size() ; j++ ){
            string str = minerals[i * 5 + j];
            if(str == "diamond")
                tmp[0]++;
            else if(str == "iron")
                tmp[1]++;
            else {
                tmp[2]++;
                cout << str << " ";                 
            }
        }
        count.push_back(tmp);
    }
    
    sort(count.begin(), count.end(), cmp);
    
    for(int i=0;i<count.size();i++){
        if(picks[0] > 0){
            picks[0]--;
            answer += count[i][0] + count[i][1] + count[i][2];
        }
        else if(picks[1]>0){
            picks[1]--;
            answer += 5 * count[i][0] + count[i][1] + count[i][2];
        }
        else if(picks[2]>0){
            picks[2]--;
            answer += 25 * count[i][0] + 5 * count[i][1] + count[i][2];
        }
        
    }
    
    
    return answer;
}
