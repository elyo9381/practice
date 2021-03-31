package me.elyowon.ndb796;


import java.util.*;


class Fruit implements Comparable<Fruit>{
    private String name;
    private int score;

    public Fruit(String name, int score){
        this.name = name;
        this.score = score;
    }

    public String getName(){
        return this.name;
    }
    public int getScore(){
        return this.score;
    }

    @Override
    public int compareTo(Fruit o) {
        if(this.score > o.score){ // > 내림차순  , < 오름 차순
            return -1;
        }
        return 1;
    }
}

public class _17_sort {


    private static void swap(int[] arr,int i,int min_index) {
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }

    private static int[] countSort() {

        int n = 10;
        int[] arr = {7,5,9,0,3,1,6,2,4,8};

        int[] cnt = new int[10];
        for (int i = 0; i < n; i++) {
            cnt[arr[i]] +=1;
        }

        return cnt;
    }

    private static int[] quickSort() {

        int n = 10;
        int[] arr = {7,5,9,0,3,1,6,2,4,8};


        quickSortimpl(arr,0,n-1);

        return arr;
    }

    private static void quickSortimpl(int[] arr,int start,int end) {
        if(start >= end) return ;
        int pivot = start;
        int left = start +1;
        int right = end;

        while(left <= right){
            while(left <= end && arr[left] <= arr[pivot]) left++;
            while(right > start && arr[right] >= arr[pivot]) right--;

            if(left > right) {
                swap(arr,pivot,right);
            }
            if(left <= right) {
                swap(arr,left,right);
            }
        }

        quickSortimpl(arr,start,right-1);
        quickSortimpl(arr,right+1, end);
    }


    private static int[] insertSort() {

        int n = 10;
        int[] arr = {7,5,9,0,3,1,6,2,4,8};

        for (int i = 1; i < n; i++) {
            for (int j = i; j>0; j--) {
                if(arr[j] < arr[j-1]){
                    swap(arr,j,j-1);
                }
                else break;
            }
        }

        return arr;
    }

    private static int[] selectionSort() {
        int n = 10;
        int[] arr = {7,5,9,0,3,1,6,2,4,8};

        for(int i = 0; i<n ; i++){
            int min_index = i;

            for(int j = i+1 ;j < n; j++){
                if(arr[min_index] > arr[j]){
                    min_index = j;
                }
            }

            swap(arr,i,min_index);
        }
        return arr;
    }


    public static void main(String[] args) {

        int[] selectArr = selectionSort();
        int[] InsertArr = insertSort();
        int[] quickArr = quickSort();
        int[] countArr = countSort();

        List<Fruit> fruits = new ArrayList<>();

        fruits.add(new Fruit("바나나",2));
        fruits.add(new Fruit("사과",5));
        fruits.add(new Fruit("당근",8));
        fruits.add(new Fruit("수박",3));


        /*
        * 그렇다면 라이브러리를 통한 내림차순은?
        * Collections.sort(fruits, Collections.reverseOrder());
        * */
        Collections.sort(fruits);

        for(Fruit fruit : fruits){
            System.out.println("fruit = " + fruit.getName() + "," + fruit.getScore());
        }
    }

}