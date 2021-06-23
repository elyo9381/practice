package me.elyowon.programers;


import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

/**
 * 2021.06.23
 */
public class 레벨1_두개뽑아서더하기 {
    public int[] solution(int[] numbers) {
        int[] answer = {};
        HashSet<Integer> hs = new HashSet<Integer>();


        List<List<Integer>> result = new ArrayList<List<Integer>>();
        ArrayList<Integer> current = new ArrayList<>();
        Arrays.sort(numbers);
        int target = 2;

        combination(numbers,target,0,current,result);

        for (List<Integer> integers : result) {
            hs.add(integers.get(0) + integers.get(1));
        }

        int i = 0;
        List collect = new ArrayList(hs);
        answer = collect.stream().sorted().mapToInt(value -> (int) value).toArray();

        return answer;

    }

    private static void combination(int[] numbers,int target,int j,ArrayList<Integer> current,List<List<Integer>> result) {
        if (target == 0) {
            ArrayList<Integer> tmp = new ArrayList<>(current);
            result.add(tmp);
            return;
        }

        for (int i = j; i < numbers.length; i++) {
            current.add(numbers[i]);
            combination(numbers,target - 1,i + 1,current,result);
            current.remove(current.size() - 1);
        }

    }


}

