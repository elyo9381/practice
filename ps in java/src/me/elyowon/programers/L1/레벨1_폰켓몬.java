package me.elyowon.programers.L1;


import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.stream.Collectors;

/**
 * 2021.06.20
 *
 * Collectors.
 * collectingAndThen -> collecting을 한후 하나의 익명메서드(람다) 사용할수있다.
 * joining ->  List가 아닌 String으로 붙여주거나 할때 사용하는 메서드
 * counting -> element의 수를 세주는 것입니다.
 */
public class 레벨1_폰켓몬 {

    public int solution(int[] nums) {
        int answer = 0;
        HashSet<Integer> hs = new HashSet<>();

        for (int num : nums) {
            hs.add(num);
        }
        if (hs.size() > nums.length / 2) answer = nums.length / 2;


        Arrays.stream(nums)
                .boxed()
                .collect(Collectors.collectingAndThen(
                        Collectors.toSet(),
                        phoneKemons -> Integer.min(phoneKemons.size(), nums.length/2 )));


        return hs.size();
    }
}
