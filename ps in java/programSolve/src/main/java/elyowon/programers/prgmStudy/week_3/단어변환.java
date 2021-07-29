package elyowon.programers.prgmStudy.week_3;

import java.util.LinkedList;

public class 단어변환 {

    class Item{
        String str;
        int move;

        public Item(String str,int move) {
            this.str = str;
            this.move = move;
        }

        public String getStr() {
            return str;
        }

        public int getMove() {
            return move;
        }
    }



    public int solution(String begin,String target,String[] words) {
        boolean[] visited = new boolean[words.length];
        int ans = dfs(begin,target,words,visited,1,Integer.MAX_VALUE);

        ans = bfs(begin,target,words);

        return ans == Integer.MAX_VALUE ? 0 : ans;
    }

    private int bfs(String begin,String target,String[] words) {
        boolean[] visit = new boolean[words.length];
        LinkedList<Item> q = new LinkedList<>();
        q.add(new Item(begin,0));

        while(!q.isEmpty()){
            Item item = q.poll();
            if(item.str.equals(target))
                return item.getMove();


            for(int i = 0; i < words.length; i++){
                if(isDiffCntJustOne(item.getStr(), words[i]) && !visit[i]){
                    visit[i] = true;
                    q.add(new Item(words[i],item.move+1));
                }
            }
        }
        return 0;
    }


    private int dfs(String begin,String target,String[] words,boolean[] visited,int cnt,int ans) {
        if (begin.equals(target)) {
            return cnt - 1;
        }

        for (int i = 0; i < words.length; i++) {
            if (!visited[i] && isDiffCntJustOne(begin,words[i])) {
                visited[i] = true;
                ans = Math.min(ans,dfs(words[i],target,words,visited,cnt + 1,ans));
                visited[i] = false;
            }
        }
        return ans;
    }

    private boolean isDiffCntJustOne(String a,String b) {
        if (a.length() != b.length()) {
            return false;
        }

        int differenceCnt = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) {
                differenceCnt++;
            }
        }
        return differenceCnt == 1 ? true : false;
    }
}