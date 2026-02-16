import java.util.*;
import java.io.*;

// BOJ 15686 - 치킨 배달
// 입력: N(도시크기) M(최대 치킨집 수) → NxN 맵 (0=빈칸, 1=집, 2=치킨집)
// 출력: 도시의 치킨 거리 최솟값
public class Main {

    static int N, M;
    static List<int[]> houses = new ArrayList<>();
    static List<int[]> chickens = new ArrayList<>();
    static int answer = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                int val = Integer.parseInt(st.nextToken());
                if (val == 1) houses.add(new int[]{i, j});
                if (val == 2) chickens.add(new int[]{i, j});
            }
        }

        // ======= 여기부터 풀이 작성 =======
        solution();
        System.out.println(answer);
    }

    // 이 메서드를 작성해
    public static int solution() {

        ArrayList<Integer> result = new ArrayList<>();
        return dfs(0,result,Integer.MAX_VALUE);
    }

    private static int dfs(int start , ArrayList<Integer>  result, int answer){
        if( result.size() == M){
            int sum = 0 ;
            for(int[] house: houses){
                int min = 987654321;
                int hx = house[0];
                int hy = house[1];
                for(int it : result){
                    int[] chichken = chickens.get(it);
                    int cx = chichken[0];
                    int cy = chichken[1];

                    int distacn = Math.abs(cx - hx)  + Math.abs(cy - hy);
                    min = Math.min(min,distacn);
                }
                sum += min;
                if( sum >= answer) break;
            }
            answer=Math.min(answer, sum);
            return answer;
        }

        for(int i = start ; i<chickens.size(); i++){
            result.add(i);
            answer = dfs(i+1,result, answer);
            result.remove(result.size()-1);
        }

        return answer;
    }


}
