#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> s;
    for(auto& n : nums){
        s.insert(n);
    }
    answer = min(s.size(), nums.size() / 2);
    return answer;
}