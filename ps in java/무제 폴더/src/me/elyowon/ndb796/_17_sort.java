package me.elyowon.ndb796;


import java.util.*;


class Fruit implements Comparable<Fruit> {
    private String name;
    private int score;

    public Fruit(String name,int score) {
        this.name = name;
        this.score = score;
    }

    public String getName() {
        return this.name;
    }

    public int getScore() {
        return this.score;
    }

    @Override
    public int compareTo(Fruit o) {
        if (this.score > o.score) { // > 내림차순  , < 오름 차순
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
            cnt[arr[i]] += 1;
        }

        return cnt;
    }

    private static int[] quickSort() {

        int n = 10;
        int[] arr = {7,5,9,0,3,1,6,2,4,8};


//        quickSortimpl(arr,0,n - 1);
        middleValueQuickSort(arr,0,n - 1);

        return arr;
    }

    private static void threeSort(int[] arr,int front,int mid,int rear) {
        if (arr[front] > arr[mid]) swap(arr,front,mid);
        if (arr[mid] > arr[rear]) swap(arr,mid,rear);
        if (arr[front] > arr[mid]) swap(arr,front,mid);
    }


    private static void middleValueQuickSort(int[] arr,int front,int rear) {

        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();

        int i, j, pivot, mid = front + (rear - front) / 2; // 초기 threeSort를 제외한 배열 안쪽의 값들을 sort하기 위해

        threeSort(arr,front,mid,rear);


        if (rear - front + 1 > 3) {
            pivot = arr[mid];
            swap(arr,mid,rear - 1);
            i = front;
            j = rear - 1;

            while (i < j) {
                while (arr[++i] < pivot && i < rear) ;
                while (arr[--j] > pivot && front < j) ;
//                if(i>=j) break;

                if (i < j) {
                    swap(arr,i,j);

                }
                if (i >= j) {
                    swap(arr,i,rear - 1);

                }

//                swap(arr,i,j);
                System.out.println("pivot = " + pivot);
            }
//            swap(arr,i,rear-1);
            middleValueQuickSort(arr,front,i - 1);
            middleValueQuickSort(arr,i + 1,rear);
        }
    }

    private static void quickSortimpl(int[] arr,int start,int end) {
        if (start >= end) return;
//        int pivot = (start+end)/2;
        int pivot = start;
        int left = start + 1;
        int right = end;

        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();

        while (left <= right) {
            while (left <= end && arr[left] <= arr[pivot]) left++;
            while (right > start && arr[right] >= arr[pivot]) right--;

            if (left > right) {
                swap(arr,pivot,right);
            }
            if (left <= right) {
                swap(arr,left,right);
            }

            System.out.println("pivot = " + pivot);
        }

        quickSortimpl(arr,start,right - 1);
        quickSortimpl(arr,right + 1,end);
    }


    private static int[] insertSort() {

        int n = 10;
        int[] arr = {7,5,9,0,3,1,6,2,4,8};

        for (int i = 1; i < n; i++) {
            for (int j = i; j > 0; j--) {
                if (arr[j] < arr[j - 1]) {
                    swap(arr,j,j - 1);
                } else break;
            }
        }

        return arr;
    }

    private static int[] selectionSort() {
        int n = 10;
        int[] arr = {7,5,9,0,3,1,6,2,4,8};

        for (int i = 0; i < n; i++) {
            int min_index = i;

            for (int j = i + 1; j < n; j++) {
                if (arr[min_index] > arr[j]) {
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

        for (int i : quickArr) {
            System.out.print(" " + i);
        }

//        List<Fruit> fruits = new ArrayList<>();
//
//        fruits.add(new Fruit("바나나",2));
//        fruits.add(new Fruit("사과",5));
//        fruits.add(new Fruit("당근",8));
//        fruits.add(new Fruit("수박",x3));




        /*
         * 그렇다면 라이브러리를 통한 내림차순은?
         * Collections.sort(fruits, Collections.reverseOrder());
         * */

//
//        Collections.sort(fruits);
//
//        for(Fruit fruit : fruits){
//            System.out.println("fruit = " + fruit.getName() + "," + fruit.getScore());
//        }
    }

}