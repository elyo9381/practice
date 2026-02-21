import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

public class early_adopter_2533_trace {
    static int n;
    static List<Integer>[] g;
    static int[][] dp; // dp[u][0]: u not selected, dp[u][1]: u selected
    static List<Integer> picked = new ArrayList<>();

    static void dfs(int u, int p) {
        dp[u][0] = 0;
        dp[u][1] = 1;

        for (int v : g[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);

            // If u is not selected, child must be selected.
            dp[u][0] += dp[v][1];
            // If u is selected, child can be either selected or not.
            dp[u][1] += Math.min(dp[v][0], dp[v][1]);
        }
    }

    static void trace(int u, int p, int state) {
        if (state == 1) {
            picked.add(u);
        }

        for (int v : g[u]) {
            if (v == p) {
                continue;
            }

            int childState;
            if (state == 0) {
                childState = 1;
            } else {
                // Tie-break: prefer 0 for deterministic output.
                childState = (dp[v][0] <= dp[v][1]) ? 0 : 1;
            }
            trace(v, u, childState);
        }
    }

    static List<List<Integer>> enumerateAllMinSets(int u, int p, int state) {
        List<List<Integer>> partial = new ArrayList<>();
        List<Integer> base = new ArrayList<>();
        if (state == 1) {
            base.add(u);
        }
        partial.add(base);

        for (int v : g[u]) {
            if (v == p) {
                continue;
            }

            List<List<Integer>> childSets = new ArrayList<>();
            if (state == 0) {
                childSets.addAll(enumerateAllMinSets(v, u, 1));
            } else {
                if (dp[v][0] < dp[v][1]) {
                    childSets.addAll(enumerateAllMinSets(v, u, 0));
                } else if (dp[v][0] > dp[v][1]) {
                    childSets.addAll(enumerateAllMinSets(v, u, 1));
                } else {
                    childSets.addAll(enumerateAllMinSets(v, u, 0));
                    childSets.addAll(enumerateAllMinSets(v, u, 1));
                }
            }

            List<List<Integer>> merged = new ArrayList<>();
            for (List<Integer> cur : partial) {
                for (List<Integer> child : childSets) {
                    List<Integer> comb = new ArrayList<>(cur.size() + child.size());
                    comb.addAll(cur);
                    comb.addAll(child);
                    merged.add(comb);
                }
            }
            partial = merged;
        }

        return partial;
    }

    static String joinSorted(List<Integer> nodes) {
        Collections.sort(nodes);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < nodes.size(); i++) {
            if (i > 0) {
                sb.append(' ');
            }
            sb.append(nodes.get(i));
        }
        return sb.toString();
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine().trim());

        @SuppressWarnings("unchecked")
        List<Integer>[] temp = (List<Integer>[]) new ArrayList[n + 1];
        g = temp;
        for (int i = 1; i <= n; i++) {
            g[i] = new ArrayList<>();
        }

        for (int i = 0; i < n - 1; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            g[a].add(b);
            g[b].add(a);
        }

        dp = new int[n + 1][2];
        dfs(1, 0);

        int rootState = (dp[1][0] <= dp[1][1]) ? 0 : 1;
        trace(1, 0, rootState);
        Collections.sort(picked);

        StringBuilder sb = new StringBuilder();
        sb.append("min_count=").append(dp[1][rootState]).append('\n');
        sb.append("early_adopters=");
        for (int i = 0; i < picked.size(); i++) {
            if (i > 0) {
                sb.append(' ');
            }
            sb.append(picked.get(i));
        }
        sb.append('\n');

        int best = Math.min(dp[1][0], dp[1][1]);
        List<List<Integer>> all = new ArrayList<>();
        if (dp[1][0] == best) {
            all.addAll(enumerateAllMinSets(1, 0, 0));
        }
        if (dp[1][1] == best) {
            all.addAll(enumerateAllMinSets(1, 0, 1));
        }

        // Deduplicate and order for stable output
        Set<String> uniqSet = new LinkedHashSet<>();
        for (List<Integer> set : all) {
            String s = joinSorted(set);
            uniqSet.add(s);
        }
        List<String> uniq = new ArrayList<>(uniqSet);
        Collections.sort(uniq);

        sb.append("all_min_sets_count=").append(uniq.size()).append('\n');
        for (String s : uniq) {
            sb.append(s).append('\n');
        }

        System.out.print(sb);
    }
}
