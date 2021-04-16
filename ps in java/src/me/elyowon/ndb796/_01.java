package me.elyowon.ndb796;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;

public class _01 {

    public static boolean ch[] = new boolean[30];
    public static ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();
    public static int arr[] = new int[30];
    public static int comBi[] = new int[30];
    public static int targetArr[] ={1,3,4,6};


    static int n;
    static int r;
    static int count = 0;

    public static void main(String[] args)  {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


        n = 4;
        r = 2;

        //순열(순서있게 배열)
        LinkedList<Integer> perArr = new LinkedList<Integer>();
        int[] perCheck = new int[n];
        permutaion(n,r,perArr,perCheck);

        System.out.println("순열끝");

        //중복 순열(순서있게 배열 + 자기자신도 포함)
        LinkedList<Integer> rePerArr = new LinkedList<>();
        rePermutation(n,r,rePerArr);
        System.out.println("중복순열끝");


        //조합 (순서관심없고 뽑은 유무 생각)
        int[] comArr = new int[r];
        combination(comArr,n,r,0,0);
        System.out.println("조합끝");

        //중복조합 (순서관심없고 뽑는 유무만 생각 + 자기자신도 포함)
        int[] reComArr = new int[r];
        reCombination(reComArr,n,r,0,0);
        System.out.println("중복조합끝");

//        dfs(0,0);
        System.out.println(count);

    }


    private static void permutaion(int n,int r,LinkedList<Integer> perArr, int[] perCheck){
        if(perArr.size() == r){
            for(var i : perArr){
                System.out.print(targetArr[i] + " ");
//                System.out.print(i + " ");
            }
            System.out.println();
            return;
        }

        for(int i = 0; i<n; i++){
            if(perCheck[i] == 0){
                perArr.add(i);
                perCheck[i] = 1;
                permutaion(n,r,perArr,perCheck);
                perCheck[i] = 0;
                perArr.removeLast();
            }
        }
    }

    private static void rePermutation(int n,int r,LinkedList<Integer> rePerArr) {
        if(rePerArr.size() == r){
            for(int i : rePerArr){
                System.out.print(i + " ");
            }
            System.out.println();
            return;
        }

        for(int i = 0; i<n; i++){
            rePerArr.add(i);
            rePermutation(n,r,rePerArr);
            rePerArr.removeLast();
        }
    }


    private static void combination(int[] comArr,int n,int r,int index,int target) {
        if(r == 0 ){
            for(int i : comArr){
                System.out.print(targetArr[i]+" ");
            }
            System.out.println();
            return ;
        }

        if(target == n) return;

        comArr[index] = target;
        combination(comArr, n, r-1,index+1,target+1); // 뽑는 경우
        combination(comArr, n, r,index,target+1); // 안뽑는 경우
    }

    private static void reCombination(int[] reComArr,int n,int r,int index,int target) {
        if(r == 0){
            for(int i : reComArr){
                System.out.print(i + " ");
            }
            System.out.println();
            return;
        }

        if(target == n) return;

        reComArr[index] = target ;
        reCombination(reComArr,n, r-1, index+1,target); // 뽑는경우
        reCombination(reComArr,n,r,index,target+1); //안뽑는 경우
    }

//    private static void dfs(int idx,int cnt) {
//
//        if(cnt == r){
//            for (int i = 0; i < n; i++) {
//                if(ch[i] == true){
//                    System.out.print(arr[i]+" ");
//                }
//            }
////            count++;
//            System.out.println();
//        }
//
////        순열
////        for (int i = 0; i < n; i++) {
////            if (ch[i] == true) continue;
////            ch[i] = true;
////            comBi[idx] = arr[i];
////            dfs(idx + 1,cnt);
////            ch[i] = false;
////        }
//
////        조합
////        for (int i = idx; i < n; i++) {
////            if(ch[i] == true) continue;
////            ch[i] = true;
////            dfs(i,cnt+1);
////            ch[i] = false;
////        }
//
//
//    }
}
