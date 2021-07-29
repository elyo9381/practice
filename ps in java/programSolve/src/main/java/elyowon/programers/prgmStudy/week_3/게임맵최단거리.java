package elyowon.programers.prgmStudy.week_3;

import java.util.LinkedList;

public class 게임맵최단거리 {

    class Point {
        int x;
        int y;
        int dis;

        public Point(int x,int y,int dis) {
            this.x = x;
            this.y = y;
            this.dis = dis;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }

        public int getDis() {
            return dis;
        }
    }

    public int solution(int[][] maps) {

        int[] dx = {-1,1,0,0};
        int[] dy = {0,0,-1,1};

        int n = maps.length;
        int m = maps[0].length;
        boolean[][] visited = new boolean[n][m];
        LinkedList<Point> moveQ = new LinkedList<>();

        moveQ.offer(new Point(0,0,1));
        visited[0][0] = true;

        while (!moveQ.isEmpty()) {
            Point now = moveQ.poll();

            if (now.getX() == n - 1 && now.getY() == m - 1)
                return now.getDis();


            for (int i = 0; i < 4; i++) {

                int nx = now.getX() + dx[i];
                int ny = now.getY() + dy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m || maps[nx][ny] == 0 || visited[nx][ny]) continue;
                visited[nx][ny] = true;
                moveQ.offer(new Point(nx,ny,now.getDis() + 1));
            }
        }

        return -1;
    }
}