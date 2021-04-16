package me.elyowon.programers;

import java.util.HashMap;
import java.util.Map;

/**
 * 1.한쪽은 1 , 다른쪽은 -1
 * 2. 1이되는지 판별하고 가능하면 진행
 * 3 모든 가중치를 0으로 만들고자함
 * <p>
 * 가중치 배열과 트리정보가 주어짐
 * 모든 가중치를 0으로 만들수 없으면 -1 출력
 * <p>
 * 최소 몇번만에 모든 가중치를 0으로 만드는가 최솟값 출력
 */
public class 모두0으로만들기 {

    private static int[] a = {-5,0,2,1,2};
    private static int[][] edges = {{0,1},{3,4},{2,3},{0,3}};

    public static void main(String[] args) {
        long result = solution(a,edges);
    }

    public static long solution(int[] a,int[][] edges) {
        long answer = -2;
        return answer;
    }
}