import java.util.*;

public class Solve2098 {

    static int n ;
    static int[][] dist;
    static int[][] dp;
    static final int INF = 987654321;

    public static boolean allVisited(boolean[] visited){
        for(int i =0 ; i< visited.length; i++){
            if( !visited[i] ) return false;
        }
        return true;
    }

    static int visitedToInt(boolean[] visited){
        int num = 0; 
        for(int i = 0 ; i<visited.length; i++){
            if(!visited[i]) continue;
            num += (1 << i);
        }
        return num;
    }

    public static int solve2(int now, int visitedMask){

        if( visitedMask == (1 << n) - 1  ){
            if( dist[now][0] == 0 ) return INF;
            return dist[now][0];
        }

        if(dp[now][visitedMask] != -1){
            return dp[now][visitedMask];
        }
        
        int min = INF;
        for(int next = 0 ; next< n ; next++ ){
            if( (visitedMask & (1 <<  next) ) == 0 && dist[now][next] != 0 ){
                int newMask = visitedMask | (1 << next);
                min = Math.min ( min, solve2(next,newMask) + dist[now][next]);
            }
        }

        return dp[now][visitedMask] = min;
    }

    public static int solve(int now, boolean[] visited ){

    
        if(allVisited(visited)) {
            if(dist[now][0] == 0) return INF;
            return dist[now][0];
        }
        

        int visitedNum = visitedToInt(visited);
        if(dp[now][visitedNum] != -1){
            return dp[now][visitedNum];
        }

        
        int min = INF;
        for(int next = 0; next <n ; next++ ){
            if(!visited[next] && dist[now][next] != 0){
                visited[next] = true;
                min = Math.min(min,solve(next , visited) + dist[now][next]);
                visited[next] = false;
            }
        }

        return dp[now][visitedNum] = min;
    }
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        int result = -1;

        dist = new int[n][n];

        for(int i = 0 ; i<n; i++){
            for(int j = 0 ; j<n; j++){
                dist[i][j] = sc.nextInt();
            }
        }

        dp = new int[n][1<<n];
        for(int i = 0 ; i<n; i++){
            Arrays.fill(dp[i],-1);
        }

        boolean[] visited = new boolean[n];
        visited[0]= true;
        int visitedMask = 1;
        result = solve2(0, visitedMask);

        System.out.println(result);
    }
}
