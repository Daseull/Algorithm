#include<string>
#include<stack>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    for(auto& c : s){
        if(c == '(') 
            st.push(c);
        else if(!st.empty() && st.top() == '(')
            st.pop();
        else
            return false;
    }
    if(!st.empty())
        return false;
    return answer;
}