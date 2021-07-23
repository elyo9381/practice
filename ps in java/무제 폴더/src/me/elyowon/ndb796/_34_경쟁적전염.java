package me.elyowon.ndb796;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

import static java.lang.Integer.parseInt;

class Virus implements Comparable<Virus>{

    private int index;
    private int second;
    private int x;
    private int y;

    public Virus(int index,int second,int x,int y) {
        this.index = index;
        this.second = second;
        this.x = x;
        this.y = y;
    }

    public int getIndex() {
        return index;
    }

    public int getSecond() {
        return second;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    @Override
    public int compareTo(Virus o) {
        if(this.index < o.index){ //  < 내림차순
            return -1;
        }
        return 1; // > 오름차순
//        return Integer.compare(this.index, o.index); // 오름차순
    }
}
public class _34_경쟁적전염 {


    public static int n, m, result = 0;
    public static int[][] graph = new int[200][200]; // 초기 맵 배열
    public static ArrayList<Virus> viruses = new ArrayList<Virus>();

    // 4가지 이동 방향에 대한 배열
    public static int[] dx = {-1, 0, 1, 0};
    public static int[] dy = {0, 1, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = parseInt(st.nextToken());
        m = parseInt(st.nextToken());

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                graph[i][j] = parseInt(st.nextToken());
                if(graph[i][j] !=0){
                    viruses.add(new Virus(graph[i][j],0,i,j));
                }
            }
        }

        Collections.sort(viruses);


        for (Virus virus : viruses) {
            System.out.println("virus = " + virus.getIndex());
        }


        Queue<Virus> q = new LinkedList<Virus>();
        for (int i = 0; i < viruses.size(); i++) {
            q.offer(viruses.get(i));
        }
        st = new StringTokenizer(br.readLine());
        int targetS = parseInt(st.nextToken());
        int targetX =parseInt(st.nextToken());
        int targetY = parseInt(st.nextToken());


        while(!q.isEmpty()){
            Virus virus = q.poll();

            if(virus.getSecond() == targetS) break;
            for(int i = 0; i<4; i++){
                int nx = virus.getX() + dx[i];
                int ny = virus.getY() + dy[i];

                if( 0<= nx && nx <n && 0 <=ny && ny < n){
                    if(graph[nx][ny] == 0){
                        graph[nx][ny] = virus.getIndex();
                        q.offer(new Virus(virus.getIndex(), virus.getSecond() + 1,nx,ny));
                    }
                }
            }
        }

        System.out.println(graph[targetX-1][targetY-1]);
    }

}
