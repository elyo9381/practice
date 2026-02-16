import java.util.*;


public class meeting_room {
    
    public int solution(int n , ArrayList<int[]> arr){

        // 끝나닌 시간을 기준으로 정렬한다. 
        arr.sort((a,b) -> a[1]!=b[1] ? Integer.compare(a[1],b[1])
    : Integer.compare(a[0],b[0]));
        // 그리고 끝나는 시간 다음에 올수있는 출발시간을 체크해서 
        // 카운트 한다. 
        // int count = 1 ;
        // int lastEnd = arr.get(0)[1] ;
        // for(int i = 1 ; i<n ;i++){
        //     int[] cur = arr.get(i);
            
        //     if(cur[0] >= lastEnd){
        //         count++;
        //         lastEnd = cur[1];
        //     }
        // }
        // 위에서 작성해보니, 아래의 코드가 이해가 간다. 
        int count = 0 ; 
        int lastEnd = 0 ;

        for(int i = 0 ; i< arr.size(); i++){
            int[] cur = arr.get(i);
            if( cur[0] >= lastEnd){
                count++;
                lastEnd = cur[1];
            }
        }

        return count;
    }
}
