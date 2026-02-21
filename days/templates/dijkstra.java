import java.io.IOException;
import java.util.*;



public class dijkstra-template-test {

    static final int INF = Integer.MAX_VALUE;
    static List<int[]>[] graph ;

    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int V = Integer.parseInt(st.nextToken());
        int E = Integer.parseInt(st.nextToken());
        int start = Integer.parseInt(br.readLine().trim());

        @SuppressWarnings("unchecked")
        List<int[]>[] g = new ArrayList[ V+1];
        graph = g;
        for(int i= 0 ; i<=V; i++){
            graph[i] = new ArrayList<>();
        }

    }
 }
