package me.elyowon.ndb796;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/*
input
K1KA5CB7

*/

class Snake {
    private int time;
    private char direction;

    public Snake(int time,char direction) {
        this.time = time;
        this.direction = direction;
    }

    public int getTime() {
        return time;
    }

    public char getDirection() {
        return direction;
    }
}

class Position{
    private int x;
    private int y;

    public Position(int x,int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }
}

public class _29_뱀 {

    public static int n,k,l;

    public static int [][] apple = new int[101][101];
    public static ArrayList<Snake> info = new ArrayList<Snake>();

    public static int dx[] = {0,1,0,-1};
    public static int dy[] = {1,0,-1,0};


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st ;

        n = Integer.parseInt(br.readLine());
        k = Integer.parseInt(br.readLine());

        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            apple[a][b] = 1;
        }

        l = Integer.parseInt(br.readLine());
        for (int i = 0; i < l; i++) {
            st = new StringTokenizer(br.readLine());
            int x  = Integer.parseInt(st.nextToken());
            String s = st.nextToken();
            char c = s.charAt(0);
            info.add(new Snake(x,c));
        }

        System.out.println(simulate());
    }
    public static int turn(int direction, char c){
        if (c == 'L') direction = (direction == 0) ? 3 : direction -1;
        else direction = (direction + 1) % 4;
        return direction;
    }

    private static int simulate() {
        int x = 1, y = 1;
        apple[x][y] = 2;

        int direction = 0;
        int time = 0;
        int index = 0;

        Queue<Position> q = new LinkedList<>();
        q.offer(new Position(x,y));

        while(true){
            int nx = x + dx[direction];
            int ny = y + dy[direction];

            if(1 <= nx && nx <=n && 1<=ny && ny <= n && apple[nx][ny] != 2){
                if(apple[nx][ny] == 0){
                    apple[nx][ny] = 2;
                    q.offer(new Position(nx,ny));
                    Position prev = q.poll();
                    apple[prev.getX()][prev.getY()] = 0;
                }
                if( apple[nx][ny] == 1){
                    apple[nx][ny] = 2;
                    q.offer(new Position(nx,ny));
                }
            }
            else {
                time +=1;
                break;
            }

            x = nx;
            y = ny;
            time +=1;
            if(index < l && time == info.get(index).getTime()){
                direction = turn(direction, info.get(index).getDirection());
                index +=1;
            }
        }

        return time;

    }
}
