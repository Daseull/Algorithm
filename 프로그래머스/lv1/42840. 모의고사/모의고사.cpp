#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int p1[5] = {1,2,3,4,5}, p2[8] = {2,1,2,3,2,4,2,5}, p3[10] = {3,3,1,1,2,2,4,4,5,5};
    int scores[3] = {0,};
    for(int i=0;i<answers.size();i++){
        if(answers[i] == p1[i%5]) scores[0]++;
        if(answers[i] == p2[i%8]) scores[1]++;
        if(answers[i] == p3[i%10]) scores[2]++;
    }
    int max = *max_element(scores, scores+3);
    for(int i=0;i<3;i++)
        if(scores[i] == max)
            answer.push_back(i+1);
    
    return answer;
}