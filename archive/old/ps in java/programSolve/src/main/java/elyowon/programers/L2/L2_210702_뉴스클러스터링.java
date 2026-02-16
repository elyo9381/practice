package elyowon.programers.L2;


import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Objects;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

/**
 * 두 집합의 교집합 크기를 합집합의 크기로 나눈값 => 자카드 유사도
 */
public class L2_210702_뉴스클러스터링 {

    private static final Integer MULTIPLIER = Character.MAX_VALUE + 1;

    public int solution1(String str1, String str2) {
        String word1 = str1.toLowerCase();
        String word2 = str2.toLowerCase();

        Map<String, Long> words1 = group(word1);
        Map<String, Long> words2 = group(word2);

        for (Map.Entry<String, Long> entry : words1.entrySet()) {
            String key = entry.getKey();
            Long value = entry.getValue();

            System.out.println("key" + key + "value" + value);
        }
        Integer intersection = getIntersection(words1, words2);
        Integer union = getUnion(words1, words2);

        if (intersection.equals(union) && union.equals(0)) {
            return MULTIPLIER;
        }

        return (int) (intersection.doubleValue() / union.doubleValue() * MULTIPLIER);
    }

    private Map<String, Long> group(String word) {
        return IntStream.range(0, word.length() - 1)
                .mapToObj(index -> word.substring(index, index + 2))
                .filter(text -> text.chars().allMatch(character -> Character.isAlphabetic((char) character)))
                .collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));
    }

    private Integer getIntersection(Map<String, Long> words1, Map<String, Long> words2) {
        return words1.entrySet().stream()
                .filter(entry -> words2.containsKey(entry.getKey()))
                .map(entry -> Math.min(entry.getValue(), words2.get(entry.getKey())))
                .mapToInt(Long::intValue)
                .sum();
    }

    private Integer getUnion(Map<String, Long> words1, Map<String, Long> words2) {
        Map<String, Long> copiedWords = new HashMap<>(words2);
        words1.forEach((key, value) -> copiedWords.put(key, Math.max(value, words2.getOrDefault(key, 0L))));

        return copiedWords.values().stream()
                .mapToInt(Long::intValue)
                .sum();

    }

    public int solution(String str1,String str2) {

        return jacade(str1,str2) * 65536;

    }

    private int jacade(String str1,String str2) {

        ArrayList<String> sList1 = new ArrayList<>();
        ArrayList<String> sList2 = new ArrayList<>();

        String temp1 = str1.toLowerCase();
        for (int i = 0; i < temp1.length() - 1; i++) {
            if (!(temp1.charAt(i) >= 'a' && temp1.charAt(i) <= 'z')) {
                continue;
            }
            if (!(temp1.charAt(i + 1) >= 'a' && temp1.charAt(i + 1) <= 'z')) {
                continue;
            }
            String twoWord = temp1.substring(i,i + 2);
            sList1.add(twoWord);
        }
        String temp2 = str2.toLowerCase();
        for (int i = 0; i < temp2.length() - 1; i++) {
            if (!(temp2.charAt(i) >= 'a' && temp2.charAt(i) <= 'z')) {
                continue;
            }
            if (!(temp2.charAt(i + 1) >= 'a' && temp2.charAt(i + 1) <= 'z')) {
                continue;
            }
            String twoWord = temp2.substring(i,i + 2);
            sList2.add(twoWord);
        }
        ArrayList<String> intersection = new ArrayList<>();
        ArrayList<String> union = new ArrayList<>();
        for (String s : sList1) {
            if (sList2.remove(s)) {
                intersection.add(s);
            }
            union.add(s);
        }

        for (String s : sList2) {
            union.add(s);
        }

        double jakard = 0;

        if (union.size() == 0) {
            jakard = 1;
        } else {
            jakard = (double) intersection.size() / (double) union.size();
        }

        return (int) (jakard * 65536);
    }

}
