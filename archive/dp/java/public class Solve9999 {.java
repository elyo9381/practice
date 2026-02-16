public class Solve9999 {

    public static void main(String[] args){ 

    }

    static boolean backtrack(){
        if( check()) return true;


        for(int i = 1 ; i<=n; i++){
            if(!visited[i]){
                visited[i] = true; 
                jw.add(i);
                backtrack() return true;
                jw.remove(jw.size()- 1);
                visited[i] = false;
            }
        }
        return false;
    }


    static coin(){
        for(int i = 2 ; i<=n ; i++){
            dp[i] = Math.min(dp[i] , dp[i-1]+1);

            if(i % 2 ==0) 
            dp[i] = Math.min(dp[i], dp[i/2]+1);
            if(i % 3 ==0) 
            dp[i] = Math.min(dp[i], dp[i/3]+1);
        }

        AraryList path = new ArrayList<>();
        int cur = n; 

        while( cur > 0){
            path.add(cur);
            if(cur %  3 ==0 && (dp[cur] == dp[cur/3]+1)){
                cur = cur/3; 
            } else if(cur %  2 ==0 && (dp[cur] == dp[cur/2]+1)){
                cur = cur/2; 
            } else {
                cur = cur -1; 
            }
        }
    }

    /**
     * 1
     *  1
     *      1
     *      2
     *      3
     *          1
     *      4
     *      5
     *      6
     *  2
     *  3
     */
    static long catalinNumber(int w, int h){
        if ( w == 0 ) return 1;
        if(dp[w][h] != 0) return dp[w][h];

        long result = 0 ;
        result += solve(w-1, h+1);

        if( h > 0){
            result += solve(w, h-1);
        }
        return dp[w][h] = result;
    }
}