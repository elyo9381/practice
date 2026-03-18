import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.*;

public class boj_13549 {
    static int n, k;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        int mx = 100000;
        int INF = Integer.MAX_VALUE;
        int[] dist = new int[mx + 1];
        Arrays.fill(dist, INF);

        ArrayDeque<Integer> dq = new ArrayDeque<>();
        dq.offerFirst(n);
        dist[n] = 0;

        while (!dq.isEmpty()) {
            int cur = dq.pollFirst();

            if (cur == k)
                break;

            int nx2 = cur * 2;
            if (0 <= nx2 && nx2 <= mx && dist[nx2] > dist[cur]) {
                dist[nx2] = dist[cur];
                dq.offerFirst(nx2);
            }

            int[] nxs = new int[] { cur + 1, cur - 1 };
            for (int it : nxs) {
                if (0 <= it && it <= mx && dist[it] > dist[cur] + 1) {
                    dist[it] = dist[cur] + 1;
                    dq.offerLast(it);
                }
            }
        }

        System.out.print(dist[k]);
        return;
    }
}