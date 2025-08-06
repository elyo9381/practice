package elyowon.programers.prgmStudy.week_3;

import java.util.ArrayList;
import java.util.LinkedList;

public class 타켓넘버 {

    public int solution(int[] number,int target) {
        int answer = 0;
        int sum = number[0];
        answer = dfs(sum,number,target,1);

        LinkedList<Integer> q = new LinkedList<Integer>();

        q.offer(0);
        q.offer(0);

        while(!q.isEmpty()){
            int level = q.poll();
            int v = q.poll();

            if(level == number.length){
                if(v == target) answer++;
            } else {
                q.offer(level +1);
                q.offer(v + number[level]);

                q.offer(level +1);
                q.offer(v - number[level]);
            }
        }

        return answer;
    }

    private int dfs(int sum,int[] number,int target,int idx) {
        if (idx >= number.length) {
            return sum == target ? 1 : 0;
        }

        int result = 0;
        result += dfs(sum + number[idx],number,target,idx + 1);
        result += dfs(sum - number[idx],number,target,idx + 1);

        return result;
    }
}