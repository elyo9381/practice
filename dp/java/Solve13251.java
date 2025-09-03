public class Solve13251 {

    static int n , k;
    static int[] stone;
    static int total  = 0 ;
    
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        stone = new int[n+1];

        for(int i = 0 ; i<n ; i++){
            stone[i] = sc.nextInt();
            total += stone[i];
        }

        k = sc.nextInt();

        double result = 0.0;
        for(int i = 0 ; i <n ; i++){
            if(stone[i] >= k)
            {
                result += comb(stone[i] , k) / comb(total , k);
            }
        }

        System.out.println(result);
    }

    static double comb(int n , int r){
        if( r < 0 || r > n) return 0;
        if( r == 0 || r == n ) return 1;

        double result = 1.0;
        for(int i = 0 ; i < r; i++){
            result = result * (n - i) / (i + 1);
        }
        return result;
    }

    static void backtrack(int start, int n , int r , List<Integer> cur){
        if( cur.size() == r){
            result.add(new ArrayList<>(cur));
            return ;
        }

        for(int i = start; i<=n; i++){
            cur.add(i);
            backtrack(i+1,n,r,cur);
            cur.remove(cur.size()-1);
        }
    }
    
    static void backtrackPermutation(int start, int n , int r , List<Integer> cur){
        if( cur.size() == r){
            result.add(new ArrayList<>(cur));
            return ;
        }

        for(int i = start; i<=n; i++){
            if(!visited[i]){
                visited[i] = true;
                cur.add(i);
                backtrack(i+1,n,r,cur);
                cur.remove(cur.size()-1);
                visited[i] = false;
            }
        }
    }
}