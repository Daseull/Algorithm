/**
[문제] : 최소 스패닝 트리 그리기
[구현] : Kruskal(Union-find) 
*/

import java.util.*;

class Solution {
    public int solution(int n, int[][] costs) {
        int answer = 0;
        
        Arrays.sort(costs, (a , b) -> a[2] - b[2]); //lambda를 이용해 배열 정렬 
        
        int[] roots = new int[n];
        for(int i=0;i<n;i++)
            roots[i] = i;
        
        for(int[] edge : costs){
            int r1 =  findRoot(roots, edge[0]);
            int r2 =  findRoot(roots, edge[1]);
            // 서로 다른 네트워크인 경우에만 간선 추가 
            if(r1 != r2){
                answer += edge[2];
                if(r1 < r2)
                    roots[r2] = r1;
                else
                    roots[r1] = r2;
            }
        }
    
        return answer;
    }
    
    public int findRoot(int[] roots, int idx){
        if(roots[idx] == idx)
            return idx;
        return roots[idx] = findRoot(roots, roots[idx]);
    }
    
}
