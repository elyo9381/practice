import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.*;

public class boj_1697 {

    static int[] dy = {1, -1};

    static int n , k ;
    static int result = 98764321;

    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        boolean[] visited = new boolean[100001];
        int[] dist = new int[100001];
        Queue<Integer> q = new LinkedList<>();
        q.offer(n);
        visited[n] = true;

        while(!q.isEmpty()){
            int cur = q.poll();

            if( cur == k){
                System.out.println(dist[cur]);
                break;
            }

            int[] next =  { cur -1 , cur + 1 , cur * 2};
            for(int ny : next){
                if( ny < 0 || ny > 100000) continue;
                if(visited[ny]) continue;
                visited[ny] = true;
                dist[ny] = dist[cur] + 1;
                q.offer(ny);
            }
        }
        return ;
    }

 
}