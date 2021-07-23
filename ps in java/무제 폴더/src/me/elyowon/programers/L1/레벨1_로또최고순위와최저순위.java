package me.elyowon.programers.L1;

import java.util.Arrays;
import java.util.Stack;

/**
 * 투포인터로 문제 접근 쉽게 접근하였다.
 * 하지만 결과값을 구할때 1-6,2-5,3-4,4-3,5-2,6-1로 매칭을 못했다.
 * 이는 자세히보면 1-6.... 합이 7이다. 그러므로 7-내가 구한 값을 뺴고 ,1 과 비교하여 맥스값을 취하면
 * 여러가지 예외처리를 안해도 된다.
 */
public class 레벨1_로또최고순위와최저순위 {


    public static void main(String[] args) {
        int[] lottos = {2,3,4,5,6,9};
        int[] win_nums = {31,10,45,1,6,19};

        int[] solution = solution(lottos,win_nums);

        for (int i : solution) {
            System.out.println("i = " + i);
        }
    }
    public static int[] solution(int[] lottos,int[] win_nums) {
        int idxLottos = 0;
        int idxWinner = 0;
        int countZero = 0;
        int equalsNum = 0;

        Arrays.sort(lottos);
        Arrays.sort(win_nums);

        while (idxLottos < lottos.length && idxWinner < win_nums.length) {
            if (lottos[idxLottos] == 0) countZero++;
            if (lottos[idxLottos] < win_nums[idxWinner]) {
                idxLottos++;
            } else if (lottos[idxLottos] > win_nums[idxWinner]) {
                idxWinner++;
            } else {
                idxLottos++;
                idxWinner++;
                equalsNum++;
            }
        }

        while (idxLottos < lottos.length) {
            if (lottos[idxLottos] == 0) countZero++;
            idxLottos++;
        }
        while (idxWinner < win_nums.length) {
            idxWinner++;
        }

        return new int[]{7-Math.max(countZero+equalsNum,1), 7-Math.max(equalsNum,1)};
    }
}
