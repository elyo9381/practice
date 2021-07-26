package elyowon.ndb796;


import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class _18_BinarySearch {


    /**
     *
     * */

    private static int recurBinarySearch(int[] arr,int target,int start,int end) {

        if(start > end) return -1;
        int mid = (start + end)/2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] > target) return recurBinarySearch(arr,target,start,mid-1);
        else return recurBinarySearch(arr,target,mid+1,end);
    }

    private static int loopBinarySearch(int[] arr,int target,int start,int end) {
        while(start <= end){
            int mid = (start + end) /2;
            if(arr[mid] == target) return mid;
            else if(arr[mid] > target) end = mid -1;
            else start = mid +1;
        }

        return -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int target = sc.nextInt();

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i]= sc.nextInt();
        }

        int result = recurBinarySearch(arr,target,0,n-1);
//        int result = loopBinarySearch(arr,target,0,n-1);

        if(result == -1){
            System.out.println("원소가 없습니다.");
        } else{
            System.out.println(result + 1);
        }
    }

}