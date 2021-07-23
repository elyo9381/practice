package me.elyowon.programers.L2;


import java.util.LinkedList;
import java.util.Queue;

/**
 * 방문했던곳 다시 방문하면 안된다.
 * dis를 체크하는 방법은 두가지 존재한다.
 * map에 다가 바로 쓰기 혹은 Pos의 멤버변수로 dis설정하기
 * visited를 boolean이 아닌 dis를 기록하는 배열로 사용하기
 *
 */
public class L2_210702_게임맵최단거리 {
    class Pos{
        int x;
        int y;
        int dis;

        int[] dx = {0,0,-1,1};
        int[] dy = {1,-1,0,0};

        public Pos(int x, int y,int dis){
            this.x = x;
            this.y = y;
            this.dis = dis;
        }
    }
    public int solution(int[][] maps) {
        int r = maps.length;
        int c = maps[0].length;
        boolean[][] visited = new boolean[r][c];
        return bfs(r,c,0,0,maps,visited);
    }

    private int bfs(int r,int c,int x,int y,int[][] maps, boolean[][] visited) {
        Queue<Pos> q =  new LinkedList<Pos>();
        q.add(new Pos(x,y,1));

        visited[x][y] = true;

        while(!q.isEmpty()){
            Pos poll = q.poll();
            int cx = poll.x;
            int cy = poll.y;


            if(cx == r-1 && cy == c-1) return poll.dis;
            for (int i= 0; i<4; i++){
                int nx = poll.x + poll.dx[i];
                int ny = poll.y + poll.dy[i];

                if(nx < 0 || ny <0 || nx >= r || ny >= c || maps[nx][ny] == 0 || visited[nx][ny] == true ) continue;

                q.add(new Pos(nx,ny,poll.dis + 1));
                visited[nx][ny] = true;


            }
        }

        return -1;
    }

}
