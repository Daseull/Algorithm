/*
[문제] : 겹치는 구간 개수 구하기 
[구현] : 구간 시작점은 +1, 끝점은 -1 하여 다 처리후 배열 한 번 순회하면서 겹치는 개수 한 번에 처리 
*/

import java.util.*;

class Solution {
    public int solution(String[][] book_time) {
        int answer = 0, start, end;
        String[] split = {}; 
        
        int[] booked = new int[24*60+10];
        for(String[] book : book_time){
            split = (book[0] + ":" + book[1]).split(":");
            start = Integer.parseInt(split[0])*60 + Integer.parseInt(split[1]);
            end = Integer.parseInt(split[2])*60 + Integer.parseInt(split[3]) + 10;
            booked[start]++;
            booked[end]--;
        }
        
        for(int i=1;i<booked.length;i++){
            booked[i] += booked[i-1];
        }
        return Arrays.stream(booked).max().getAsInt();
        
    }
}
