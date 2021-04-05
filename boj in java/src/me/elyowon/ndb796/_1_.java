package me.elyowon.ndb796;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

import static java.lang.System.exit;
import static java.lang.System.in;

public class _1_ {

    public static ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();
    public static boolean ch[] = new boolean[30];
    public static int arr[] = new int[30];
    public static int comBi[] = new int[30];


    static int n;
    static int r;
    static int count = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i <n; i++) {
            int a;
            a = Integer.parseInt((st.nextToken()));
            arr[i] = a;
        }


        dfs(0,0);
        System.out.println(count);

    }

    private static void dfs(int idx,int cnt) {

        if(cnt == r){
            for (int i = 0; i < n; i++) {
                if(ch[i] == true){
                    System.out.print(arr[i]+" ");
                }
            }
//            count++;
            System.out.println();
        }

//        순열
//        for (int i = 0; i < n; i++) {
//            if (ch[i] == true) continue;
//            ch[i] = true;
//            comBi[idx] = arr[i];
//            dfs(idx + 1,cnt);
//            ch[i] = false;
//        }

//        조합
//        for (int i = idx; i < n; i++) {
//            if(ch[i] == true) continue;
//            ch[i] = true;
//            dfs(i,cnt+1);
//            ch[i] = false;
//        }


    }
}
