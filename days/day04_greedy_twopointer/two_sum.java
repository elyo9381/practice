import java.util.*;


public class two_sum {
    
    public int solution(int n , int[] arr , int x){

        Arrays.sort(arr);

        int ridx = arr.length -1; 
        int lidx = 0;
        int count = 0;

        while( lidx < ridx){

            if( arr[lidx] + arr[ridx] < x){
                lidx++;
            } else if( arr[lidx] + arr[ridx] == x ){
                count++;
                lidx++;
                ridx--;
            } else {
                ridx--;
            }
        }
        return count;
    }
}
