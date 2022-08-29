#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector<int> scores(8, 0);
    map<char,int> typeToInt;
    typeToInt.insert({'R', 0});
    typeToInt.insert({'T', 1});
    typeToInt.insert({'C', 2});
    typeToInt.insert({'F', 3});
    typeToInt.insert({'J', 4});
    typeToInt.insert({'M', 5});
    typeToInt.insert({'A', 6});
    typeToInt.insert({'N', 7});
    int points[7][2] = {{3,0}, {2,0}, {1,0}, {0,0}, {0, 1}, {0,2}, {0,3}};
    
    for(int i=0;i<survey.size();i++){
        scores[typeToInt[survey[i][0]]] += points[choices[i] - 1][0];
        scores[typeToInt[survey[i][1]]] += points[choices[i] - 1][1];
    }

    if(scores[0] >= scores[1])
        answer.push_back('R');
    else 
        answer.push_back('T');
    if(scores[2] >= scores[3])
        answer.push_back('C');
    else 
        answer.push_back('F');
    if(scores[4] >= scores[5])
        answer.push_back('J');
    else 
        answer.push_back('M');
    if(scores[6] >= scores[7])
        answer.push_back('A');
    else 
        answer.push_back('N');
    
    
    return answer;
}