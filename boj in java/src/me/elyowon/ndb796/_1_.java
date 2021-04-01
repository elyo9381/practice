package me.elyowon.ndb796;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

import static java.lang.System.exit;

public class _1_ {

    public static ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();
    public static int ch[] = new int[10000];
    public static int dis[] = new int[10000];
    static int[] dx = new int[3];

    static int s;
    static int e;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
         s = Integer.parseInt(st.nextToken());
        e = Integer.parseInt(st.nextToken());

        for (int i = 0; i < 30; i++) {
            graph.add(new ArrayList<Integer>());
        }


//        for (int i = 0; i <M; i++) {
//            st = new StringTokenizer(br.readLine());
//            int n = Integer.parseInt(st.nextToken());
//            int m = Integer.parseInt(st.nextToken());
//            graph.get(n).add(m);
//        }

        bfs(s);



    }

    private static void bfs(int start) {
        Queue<Integer> q = new LinkedList<Integer>();

        q.offer(start);
        ch[start] = 1;
        int cnt = 0;

        while(!q.isEmpty()){
            int x = q.poll();

            for(int i = 0; i<3; i++){
                int y = x + dx[i];

                if(y == e){
                    System.out.println(cnt);
                    exit(0);
                }

                if(ch[y] == 0){
                    ch[y] = ch[x]+1;
                    q.offer(y);
                }
            }
        }
    }
}
