package elyowon.programers.L2;


import java.util.LinkedList;
import java.util.Queue;

/**
 */
public class L2_210702_프린터 {

    class paper{
        int item;
        int priority;

        public paper(int item, int priority){
            this.item = item;
            this.priority = priority;
        }
    }

    public int solution(int[] priorities, int location){
        int answer = 1;

        Queue<paper> q = new LinkedList<>();


        int idx = 0;
        for (int priority : priorities) {
            q.add(new paper(idx,priority));
            idx++;
        }


        while(!q.isEmpty()){

            paper poll = q.poll();

            for (paper item : q) {
                if(item.priority > poll.priority){
                    q.add(poll);
                    poll = null;
                    break;
                }
            }
            if(poll != null){
                if(poll.item == location){
                    return answer;
                } else {
                    answer++;
                }
            }
        }
        return answer;
    }
}
