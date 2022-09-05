#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(auto& cmd : commands){
        int i = cmd[0], j = cmd[1], k =cmd[2];
        vector<int> arr(array.begin() + i -1, array.begin() + j);
        sort(arr.begin(), arr.end());
        answer.push_back(arr[k-1]);
    }
    return answer;
}