import java.io.*;
import java.util.*;

public class Solve9934 {

    static int k ;
    static int[] inorder;
    static ArrayList<Integer>[] levels;

    public static void main(String[] args)throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        k = Integer.parseInt(br.readLine());
        int n = (1<<k) -1;
        inorder = new int[n];
        levels = new ArrayList[k];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) {
            inorder[i] = Integer.parseInt(st.nextToken());
        }

        for(int i = 0  ; i< k ; i++){
            levels[i] = new ArrayList<>();
        }

        solve(0 , n-1 , 0);

        for(int i = 0. ;i<k ;i++){
            for(int node : levels[i]){
                System.out.print(node + " ");
            }
            System.out.println();
        }
    }

    static void solve(int left , int right , int level){
        if( left > right) return ;

        int mid = (left + right) / 2;
        levels[level].add(inorder[mid]);

        solve(left, mid - 1, level +1);
        solve(mid +1 , right, level +1);
    }
}