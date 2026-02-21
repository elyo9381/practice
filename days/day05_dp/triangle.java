import java.util.*;


public class triangle{

    /**
     * triangle 	result
        [[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]] 	30
        트리 구조에서 dfs 로 내려가는게 높이가 500까지다 
        트리 구조에서 레벨이 500이면, 최상위에서 갈수있는 방향은 2가지 
        2^500인것 같다. 이건 직접 계산이 불가능이다. 
        그러므로 dp를 사용해야한다. 
     * @param triangle
     * @return
     */
    public int solution(int[][] triangle){

        /**
         * 아 2차원 배열로 트리가 주어졌을대, 이걸 dfs 하는방법을 모르겠네 ;;
         * -> 2차월 배열이 주어졌을때는 
         * x,y => (x+1,y ) , (x+1,y+1) 이런식으로 레벨을 탐색하면 될듯 ;
         */

        int n = triangle.length;
        int[][] dp = new int[n][n];
        dp[0][0] = triangle[0][0];

        int answer = 0 ;
        for(int i = 1; i<n; i++){
            for(int j = 0; j<=i; j++){
                int fromLeftUp = ( j>0 ) ? dp[i-1][j-1] : 0 ;
                int fromUp =  (j<i) ? dp[i-1][j] : 0;
                dp[i][j] = Math.max(fromLeftUp,fromUp)+ triangle[i][j];
            }
            
        }

        for(int j = 0 ; j<n ;j++) answer = Math.max(answer , dp[n-1][j]);

        return answer; 

        // return dfs(0,0,dp,triangle);
    }
    private int dfs( int x , int y , int[][] dp, int[][] triangle ){

        if( x == triangle.length-1) return triangle[x][y];

        if(dp[x][y] !=-1 ) return dp[x][y];

        int down = dfs(x+1, y, dp,triangle);
        int downRight = dfs(x+1, y+1, dp,triangle);

        dp[x][y] = triangle[x][y] + Math.max(down, downRight);

        return dp[x][y];
    }
}