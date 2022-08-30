#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0, size = queue1.size(), idx1 = 0, idx2 = 0;
    long long sum1 = 0, sum2 = 0; 
    
    for(int i=0;i<size;i++){
        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    if((sum1 + sum2) % 2) 
        return answer = -1;
    
    int elem;
    while(sum1 != sum2){
        if(sum1 > sum2){
            elem = queue1[idx1++];
            sum1 -= elem;
            sum2 += elem;
            queue2.push_back(elem); 
        }
        else{
            elem = queue2[idx2++];
            sum1 += elem;
            sum2 -= elem;
            queue1.push_back(elem);
        }
        answer++;
        if(queue1.empty() || queue2.empty()) 
            return answer = -1;
        if(answer > size * 2 + 2)
            return answer = -1;
            
    }
    
    return answer;
}