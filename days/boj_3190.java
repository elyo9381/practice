import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.*;

public class boj_3190 {

    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};
    static int n , k , l;

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());

        int[][] map = new int[n][n];
        
        st = new StringTokenizer(br.readLine());
        k = Integer.parseInt(st.nextToken());

        for(int i = 0 ; i<k; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken())-1;
            int y = Integer.parseInt(st.nextToken())-1;
            map[x][y] = 1;
        }
        int time = 0; 

        st = new StringTokenizer(br.readLine());
        l = Integer.parseInt(st.nextToken());

        HashMap<Integer,Character> turns = new HashMap<>();
        for(int i = 0 ; i<l;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            char b = st.nextToken().charAt(0);
            turns.put(a,b);
        }

        Deque<int[]> snake = new ArrayDeque<>();
        snake.addFirst(new int[]{0,0});
        map[0][0] = 2;
        int d = 0;


        while(true){
            time++;

            int[] head = snake.getFirst();
            int nx = dx[d] + head[0];
            int ny = dy[d] + head[1];

            if( nx < 0 || ny <0 || nx>=n || ny >= n || map[nx][ny] == 2) break;


            if(map[nx][ny] != 1){
                int[] tail = snake.removeLast();
                map[tail[0]][tail[1]] = 0;
            }
            snake.addFirst(new int[]{nx,ny});
            map[nx][ny] = 2;

            if( turns.containsKey(time) ){
                d = (turns.get(time) == 'D') ? (d + 1) % 4 : (d + 3) % 4 ;
            }
        }


        System.out.println(time);
    }
}