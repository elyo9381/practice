package elyowon.programers.L2;


import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

/**
 * 나의 풀이는 스플릿한뒤 n^2으로 비교하는 방법이었다.
 *
 * 구글신의 참고 코드는 스플릿한뒤, - 를 포함 한 경우의 key를 만들어 해쉬에 넣는다.
 * 그리고 각 키의 스코어가 존재하므로 이를 포함할 list를 밸류로 갖는다.
 *
 * 경럭을 검색한후 존재하면 밾류리스트에서 이진탐색으로 lowbound를 찾아 전체 길이에서 lowbound를 빼면 이것보다 큰 값이 된다.
 */
public class L2_210707_순위검색 {

    HashMap<String, ArrayList<Integer>> hs = new HashMap<>();

    public int[] solution(String[] info,String[] query) {
        int[] answer = new int[query.length];

        makeKey(info);

        hs.forEach((key,value) -> Collections.sort(value));

        for (int i = 0; i < query.length; i++) {
            String[] temp = query[i].replaceAll(" and ", " ").split(" ");

            String key = IntStream.of(0,1,2,3).mapToObj(j -> temp[j]).collect(Collectors.joining());
            if (hs.get(key) == null) {
                answer[i] = 0;
                continue;
            }
            ArrayList<Integer> hsValueList = hs.get(key);
            int score = Integer.parseInt(temp[4]);
            answer[i] = binarySearch(hsValueList,score);
        }

        return answer;
    }

    private int binarySearch(ArrayList<Integer> hsValueList,int target) {

        int left = 0;
        int right = hsValueList.size();
        int mid = 0;

        while (right > left) {

            mid = (left + right) / 2;
            if (hsValueList.get(mid) >= target)
                right = mid;
            else left = mid + 1;

        }
        return hsValueList.size() - left;
    }

    private void makeKey(String[] info) {

        for (String s : info) {
            String[] temp = s.split(" ");

            String[] language = {temp[0],"-"};
            String[] department = {temp[1],"-"};
            String[] career = {temp[2],"-"};
            String[] food = {temp[3],"-"};
            int score = Integer.parseInt(temp[4]);


            for (String value : language) {
                for (String item : department) {
                    for (String element : career) {
                        Arrays.stream(food).map(s1 -> value + item + element + s1).forEach(key -> {

                            if (hs.get(key) == null) {
                                ArrayList<Integer> arr = new ArrayList<>();
                                arr.add(score);
                                hs.put(key,arr);
                            } else {
                                ArrayList<Integer> arr = hs.get(key);
                                arr.add(score);
                                hs.put(key,arr);

                                hs.computeIfAbsent(key , k-> hs.get(key));
                            }
                        });
                    }
                }
            }
        }

        return;
    }



    class Apply {
        String language;
        String department;
        String career;
        String food;
        int score;

        public Apply(String[] splitStr) {
            this.language = splitStr[0];
            this.department =  splitStr[1];
            this.career =  splitStr[2];
            this.food =  splitStr[3];
            this.score = Integer.parseInt(splitStr[4]);
        }

        @Override
        public String toString() {
            return "Apply{" +
                    "language='" + language + '\'' +
                    ", department='" + department + '\'' +
                    ", career='" + career + '\'' +
                    ", food='" + food + '\'' +
                    ", score=" + score +
                    '}';
        }
    }

    public int[] solution1(String[] info,String[] query) {
        int[] answer = {};
        ArrayList<Apply> appliesInfo = new ArrayList<Apply>();

        for (String s : info) {
            String[] split = s.split("[\\s]");

            appliesInfo.add(new Apply(split));
        }


        ArrayList<Apply> appliesQuery = new ArrayList<>();

        for (String s : query) {
            String[] split = s.split("[\\s]([a](.)[d])?[\\s]?");

            // for (String s1 : split) {
            // System.out.println(s1);
            // }
            appliesQuery.add(new Apply(split));
        }




        answer = Search(appliesInfo,appliesQuery);


        return answer;
    }

    private int[] Search(ArrayList<Apply> appliesInfo,ArrayList<Apply> appliesQuery) {

// for (Apply applyer : appliesQuery) {
        // System.out.println(applyer.toString());
        // }

        ArrayList<Integer> result = new ArrayList<>();

        for (Apply query : appliesQuery) {
            int count = 0;
            for (Apply info : appliesInfo) {

                if((query.language.equals(info.language) || query.language.equals("-"))
                        && (query.department.equals(info.department) || query.department.equals("-"))
                        && (query.career.equals(info.career) || query.career.equals("-"))
                        && (query.food.equals(info.food) || query.food.equals("-")) ){

                    if(query.score <= info.score ) {
                        count += 1;
                    }
                }
            }
            System.out.println("count = " + count);
            result.add(count);
        }
        return result.stream().mapToInt(i->i).toArray();
    }
}

