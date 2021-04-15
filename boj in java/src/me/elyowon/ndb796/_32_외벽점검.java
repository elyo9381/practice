package me.elyowon.ndb796;


import java.util.ArrayList;



class Permutation {
    private int n;
    private int r;
    private int[] now;
    private ArrayList<ArrayList<Integer>> result;

    public Permutation(int n,int r) {
        this.n = n;
        this.r = r;
        this.now = new int[r];
        this.result = new ArrayList<ArrayList<Integer>>();
    }

    public ArrayList<ArrayList<Integer>> getResult() {
        return result;
    }

    public void swap(int[] arr,int i,int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public void permutation(int[] arr,int depth) {
        if (depth == r) {
            ArrayList<Integer> temp = new ArrayList<>();
            for (int i = 0; i < now.length; i++) {
                temp.add(now[i]);
            }
            result.add(temp);
            return;
        }

        for (int i = depth; i < n; i++) {
            swap(arr,i,depth);
            now[depth] = arr[depth];
            permutation(arr,depth + 1);
            swap(arr,i,depth);
        }
    }
}
//
// for(int i = 0; i<n; i++){
//        if(perCheck[i] == 0){
//        perArr.add(i);
//        perCheck[i] = 1;
//        permutaion(n,r,perArr,perCheck);
//        perCheck[i] = 0;
//        perArr.removeLast();
//        }
//        }

public class _32_외벽점검{

    private static int n = 12;
    private static int[] weak = {1,5,6,10};
    private static int[] dist = {1,2,3,4};

    public static void main(String[] args) {
        int result = solution(n, weak, dist);
        System.out.println(result);
    }

    public static int solution(int n,int[] weak,int[] dist) {
        ArrayList<Integer> weakList = new ArrayList<Integer>();
        for (int i = 0; i < weak.length; i++) {
            weakList.add(weak[i]);
        }
        for (int i = 0; i < weak.length; i++) {
            weakList.add(weak[i] + n);
        }
        int answer = dist.length + 1;

        Permutation perm = new Permutation(dist.length, dist.length);
        perm.permutation(dist, 0);

        ArrayList<ArrayList<Integer>> distList = perm.getResult();

        for (int start = 0; start < weak.length; start++) {
            for (int i = 0; i < distList.size(); i++) {
                int cnt = 1;
                int position = weakList.get(start) + distList.get(i).get(cnt - 1);
                for (int index = start; index < start + weak.length; index++) {
                    if (position < weakList.get(index)) {
                        cnt += 1;
                        if (cnt > dist.length) {
                            break;
                        }
                        position = weakList.get(index) + distList.get(i).get(cnt - 1);
                    }
                }
                answer = Math.min(answer, cnt);
            }
        }
        if (answer > dist.length) {
            return -1;
        }
        return answer;
    }
}
