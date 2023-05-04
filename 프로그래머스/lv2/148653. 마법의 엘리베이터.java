// https://school.programmers.co.kr/learn/courses/30/lessons/148653

import java.util.*;

class Solution {
    public int solution(int storey) {
        return recur(storey);
    }
    
    public int recur(int a){
        if(a < 10)
            return Math.min(a, 10-a+1);
        
        int curr = a%10, next = a/10;
        return Math.min(curr + recur(next), (10-curr) + recur(next+1));
    }
}
