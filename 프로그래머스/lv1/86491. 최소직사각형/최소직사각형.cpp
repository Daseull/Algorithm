#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    vector<int> v1, v2;
    for(auto& size : sizes){
        v1.push_back(min(size[0], size[1]));
        v2.push_back(max(size[0], size[1]));
    }
    sort(v1.begin(), v1.end()); sort(v2.begin(), v2.end());
    return answer = v1.back() * v2.back();
}