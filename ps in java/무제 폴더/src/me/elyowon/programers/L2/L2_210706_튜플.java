package me.elyowon.programers.L2;


import java.util.*;
import java.util.stream.Stream;

/**
 *
 */
public class L2_210706_튜플 {

    public int[] solution(String s){
        ArrayList<Integer> list = new ArrayList<>();

        s = s.substring(2, s.length() - 1);
        String[] arr  = s.split("[,\\{]");
        int[] answer = new int[arr.length];

        Arrays.sort(arr, (a,b) -> a.length() - b.length());

        for (int i = 0; i < arr.length; i++) {
            arr[i] = arr[i].substring(0, arr[i].length()-1);
        }

        for(int i =0; i<arr.length; i++){
            String[] sub = arr[i].split(",");
            for(String j : sub){
                int num = Integer.parseInt(j);
                if(!list.contains(num))
                    list.add(num);
            }
        }

        for(int i=0; i<list.size(); i++){
            answer[i] = list.get(i);
        }



        return list.stream().mapToInt(i -> i ).toArray();
    }

    public int[] solution1(String s) {
        Set<String> set = new HashSet<>();
        String[] arr = s.replaceAll("[{]", " ").replaceAll("[}]", " ").trim().split(" , ");
        Arrays.sort(arr, (a, b)->{return a.length() - b.length();});
        int[] answer = new int[arr.length];
        int idx = 0;
        for(String s1 : arr) {
            for(String s2 : s1.split(",")) {
                if(set.add(s2)) answer[idx++] = Integer.parseInt(s2);
            }
        }
        return answer;
    }


    Map<Integer,Integer> counts = new LinkedHashMap<>();
    public int[] solution2(String s) {
        Stream.of(s.replaceAll("[}{]", "").split(",")).mapToInt(Integer::parseInt)
                .forEach(i -> counts.merge(i, 1, Integer::sum));

        for (Map.Entry<Integer, Integer> hs : counts.entrySet()) {
            System.out.println(hs.getKey()+ " : "+ hs.getValue());
        }
        return counts.entrySet().stream().sorted(Collections.reverseOrder(Map.Entry.comparingByValue()))
                .map(Map.Entry::getKey).mapToInt(x -> x).toArray();
    }
}
