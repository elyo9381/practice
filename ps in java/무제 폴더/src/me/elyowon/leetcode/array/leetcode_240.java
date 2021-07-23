package me.elyowon.leetcode.array;


public class leetcode_240 {

    /**
     *
     * 시작 컬럼음 n-1, 로우는 0으로 시작한다.
     * 정렬된 2차원 Matrix에서 검색은 우상단에서 target값보다 크면 해당 row에는 값이 없다는 것이다.
     * 이를 이용해서 크면 로우를 하나 늘려 다음 로우를 선택한다.
     * 다음 로우의 값에서 target작으면 해당 컬럼의 값들중에는 target이 없다는 뜻으로
     * col을 하나 줄인다.
     *
     * @param args
     */

    public static void main(String[] args) {

        int[][] matrix = {{1,3,5,7},{2,8,11,12},{4,9,14,19},{6,15,25,40}};
        int target = 11;
        boolean result = SearchNumInMatrix(matrix,target);

        System.out.println("result = " + result);

    }

    private static boolean SearchNumInMatrix(int[][] matrix,int target) {

        int r = matrix.length;
        int c = matrix[0].length;

        int curRow = 0;
        int curCol = matrix[0].length - 1;

        while (curRow < r && curCol >= 0) {
            if (matrix[curRow][curCol] == target) {
                return true;
            }
            if (matrix[curRow][curCol] > target) {
                curCol--;
            } else {
                curRow++;
            }
        }
        return false;
    }



    private static void swap(int[] nums,int num,int num1) {
        int temp;
        temp = nums[num];
        nums[num] = nums[num1];
        nums[num1] = temp;
    }


}
