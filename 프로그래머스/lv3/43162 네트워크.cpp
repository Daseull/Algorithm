/**
A-B & A-c = B-C
분리집합 사용
*/

#include <string>
#include <vector>

using namespace std;

int findRoot(vector<int>& parent, int idx){
    if(parent[idx] == idx)
        return idx;
    return parent[idx] = findRoot(parent, parent[idx]);
}

void Union(vector<int>& parent, int u, int v){
    int pu = findRoot(parent, u), pv = findRoot(parent, v);
    if(pu == pv)
        return;
    if(pu < pv){
        parent[pv] = pu;
    }
    else{
        parent[pu] = pv;
    }
}

int solution(int n, vector<vector<int>> computers) {
    
    int answer = 0;
    
    vector<int> parent(n);
    for(int i=0;i<n;i++)
        parent[i] = i;
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(computers[i][j])
                Union(parent, i, j);
        }
    }
    
    for(int i=0;i<n;i++)
        if(parent[i] == i)
            answer++;
    
    
    return answer;
}
