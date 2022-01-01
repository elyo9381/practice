package elyowon.programers.prgmStudy.week_4;

public class 정수삼각형 {
    public int solution(int[][] triangle) {

        int n = triangle.length;
        int[][] dp = new int[n][n];
        boolean check = false;
        for (int i = n - 1; i > 0; i--) {
            int triangleBottonSize = triangle[i].length;
            if (check) {
                for (int j = 0; j < triangleBottonSize - 1; j++) {
                    dp[i - 1][j] += Math.max(dp[i][j],dp[i][j + 1]) + triangle[i - 1][j];
                }
            } else {
                for (int j = 0; j < triangleBottonSize - 1; j++) {

                    int a = Math.max(triangle[i][j],triangle[i][j + 1]);
                    dp[i - 1][j] = a + triangle[i - 1][j];
                }
            }
            check = true;
        }
        return dp[0][0];
    }

//    public int solution(int[][] triangle) {
//        int sum =0;
//        return dfs(0,0,triangle, sum,Integer.MIN_VALUE);
//    }
//
//    private int dfs(int level,int j,int[][] triangle,int sum,int max){
//        if(level == triangle.length){
//            return Math.max(max,sum);
//        }
//
//        sum = sum + triangle[level][j];
//        int result1=dfs(level+1,j,triangle,sum, max);
//        int result2=dfs(level+1,j+1,triangle,sum, max);
//
//        return Math.max(result1,result2);
//    }
}