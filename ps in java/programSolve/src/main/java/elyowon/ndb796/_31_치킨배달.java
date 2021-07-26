package elyowon.ndb796;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

/*
input
5 2
0 2 0 1 0
1 0 1 0 0
0 0 0 0 0
2 0 0 1 1
2 2 0 1 2

*/


class Combination{
    private int n;
    private int r;
    private int[] now; // 현재 조합
    private ArrayList<ArrayList<Position>> result;

    public ArrayList<ArrayList<Position>> getResult() {
        return result;
    }

    public Combination(int n,int r) {
        this.n = n;
        this.r = r;
        this.now = new int[r];
        this.result = new ArrayList<ArrayList<Position>>();
    }

    public void combination(ArrayList<Position> arr,int depth,int index,int target){
        if(depth == r){
            ArrayList<Position> temp = new ArrayList<>();
            for (int i = 0; i < now.length; i++) {
                temp.add(arr.get(now[i]));
            }
            result.add(temp);
            return;
        }

        if(target == n) return;
        now[index] = target;
        combination(arr,depth+1,index+1,target+1);
        combination(arr,depth,index,target+1);
    }
}
//
//class Position {
//    private int x;
//    private int y;
//
//    public Position(int x,int y) {
//        this.x = x;
//        this.y = y;
//    }
//
//    public int getX() {
//        return x;
//    }
//
//    public int getY() {
//        return y;
//    }
//}


public class _31_치킨배달{

    public static int n,m;
    public static int[][] arr = new int[50][50];
    public static ArrayList<Position> chicken = new ArrayList<>();
    public static ArrayList<Position> house = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

//        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if(arr[i][j] == 1) house.add(new Position(i,j));
                else if(arr[i][j] == 2) chicken.add(new Position(i,j));
            }
        }

        Combination comb = new Combination(chicken.size(),m);
        comb.combination(chicken,0,0,0);
        ArrayList<ArrayList<Position>> chickenList = comb.getResult();

        int result = (int) 1e9;

        for (int i = 0; i < chickenList.size(); i++) {
            result = Math.min(result , getSum(chickenList.get(i)));
        }
        System.out.println(result);
    }

    private static int getSum(ArrayList<Position> candidates) {
        int result = 0;

        for (int i = 0; i < house.size(); i++) {
            int hx = house.get(i).getX();
            int hy = house.get(i).getY();

            int temp = (int) 1e9;
            for (int j = 0; j < candidates.size(); j++) {
                int cx = candidates.get(j).getX();
                int cy = candidates.get(j).getY();
                temp = Math.min(temp, Math.abs(hx - cx) + Math.abs(hy - cy));
            }

            result += temp;
        }
        return result;
    }


}
