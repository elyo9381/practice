public class Solve16986 {


    static int n , k;
    static int[][] map;
    static int[] kh , mh;
    static boolean[] visited;
    static ArrayList<Integer> jw;

    public static void main(String[] args) {


        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        k = sc.nextInt();

        map = new int[n+1][n+1];

        for(int i = 1 ; i <=n ; i++){
            for( int j = 1 ; j <=n ;j++){
                map[i][j] = sc.nextInt();
            }
        }

        kh = new int[20];
        mh = new int[20];

        for(int i=0 ; i<20; i++) kh[i] = sc.nextInt();
        for(int i=0 ; i<20; i++) mh[i] = sc.nextInt();

        jw = new ArrayList<>();
        visited = new boolean[n+1];
        System.out.println(backtrack() ? 1 : 0);
    }

    static boolean backtrack(){
        if(check()) {
            return true;
        }

        for(int i = 1 ; i<=n ;i++){
            if(!visited[i]){
                visited[i] = true;
                jw.add(i);
                if(backtrack()) return true;
                jw.remove(jw.size() - 1);
                visited[i] = false;
            }
        }
        return false;
    }

    static boolean check(){
        int[] wins = new int[3];
        int[] players = {0,1};

        int jIdx = 0 , kIdx = 0 , mIdx = 0;
        int hand1 = 0, hand2 = 0;

        for(int game = 0 ; game < 20; game++){

            int p1 = players[0] , p2 = players[1];

            if(p1 == 0){
                if( jIdx >= jw.size() ) return false;
                hand1 = jw.get(jIdx++);
            } else if (p1 == 1){
                hand1 = kh[kIdx++];
            } else {
                hand1 = mh[mIdx++];
            }
            
            if(p2 == 0){
                if( jIdx >= jw.size() ) return false;
                hand2 = jw.get(jIdx++);
            } else if (p2 == 1){
                hand2 = kh[kIdx++];
            } else {
                hand2 = mh[mIdx++];
            }

            int winner = 0 ;
            if( map[hand1][hand2] == 2){
                winner = p1;
            } else {
                winner = p2;
            }

            wins[winner]++;

            if(wins[winner] == k) return winner == 0;

            int waiter = 3 - p1 - p2;

            players[0] = winner;
            players[1] = waiter;
        }
        return false;
    }
}