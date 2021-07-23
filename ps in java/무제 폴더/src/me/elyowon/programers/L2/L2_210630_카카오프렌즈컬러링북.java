package me.elyowon.programers.L2;


import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

/**
 *
 * 아이구 븅딱아.... 큐에 입력 잘하자 ... ㅇ */
public class L2_210630_카카오프렌즈컬러링북 {

    class pos{
        int x;
        int y;

        pos(int x , int y ){
            this.x = x;
            this.y = y;
        }
    }

    public int[] dx = {0,0,1,-1};
    public int[] dy = {1,-1,0,0};

    public int[] solution(int m, int n, int[][] picture){
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;

        boolean[][] check = new boolean[m][n];

        int cnt = 0;
        int max = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(check[i][j] == false && picture[i][j] !=0){
                    max = Math.max(max,bfs(i,j,picture,check));
                    cnt++;
                }
            }
        }


        int[] answer = new int[2];
        answer[0] = cnt;
        answer[1] = max;


        return answer;
    }

    private int bfs(int x,int y,int[][] picture, boolean[][] check) {

        Queue<pos> q = new LinkedList<pos>();
        check[x][y] = true;
        q.add(new pos(x,y));

        int cnt = 1;

        while(!q.isEmpty()){

            pos poll = q.poll();

            int cx = poll.x;
            int cy = poll.y;


            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if( nx < 0 || ny <0
                        || nx>= picture.length || ny >= picture[0].length
                        || check[nx][ny] == true || picture[nx][ny] !=picture[cx][cy])
                    continue;

                check[nx][ny] = true;
                q.add(new pos(nx,ny));
                cnt++;
            }
        }

        return cnt;
    }
}
