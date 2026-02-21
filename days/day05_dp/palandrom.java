import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class palandrom {

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());

        int[] arr = new int[n];
        boolean[][] dp = new boolean[n][n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int m = Integer.parseInt(br.readLine().trim());
        ArrayList<int[]> rangeArr = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken()) - 1;
            int y = Integer.parseInt(st.nextToken()) - 1;
            rangeArr.add(new int[]{x, y});
        }

        // 길이 1 구간
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // 길이 2 ~ n 구간
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                if (arr[i] == arr[j]) {
                    if (len == 2) {
                        dp[i][j] = true;
                    } else if (dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                    }
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int[] pair : rangeArr) {
            sb.append(dp[pair[0]][pair[1]] ? 1 : 0).append('\n');
        }

        System.out.print(sb);
    }
}
