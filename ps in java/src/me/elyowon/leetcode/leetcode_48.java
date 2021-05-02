package me.elyowon.leetcode;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import static java.lang.Math.abs;

public class leetcode_48 {

    /**
     *
     * 2D Matrix를 옮길때는 4곳의 좌표를 swap하면 된다. 그러면 90도 rotation이 된다.
     * 이를 여러번 반복하면 180 270등이 가능한것이다.
     * dir을 설정한다면 말이다.
     *
     * @param args
     */

    public static void main(String[] args) {

        int[][] matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

        int[][] result = RotateMatrix(matrix);

        for (int[] ints : result) {
            for (int i = 0; i < ints.length; i++) {
                System.out.print(" " + ints[i]);
            }
            System.out.println();
        }

    }

    private static int[][] RotateMatrix(int[][] matrix) {

        int len = matrix.length;
        for (int y = 0; y < len/2 ; y++) {
            for (int x = 0; x < (len+1)/2; x++) {

                Pos pos1 = newPosition(len,new Pos(y,x));
                Pos pos2 = newPosition(len,pos1);
                Pos pos3 = newPosition(len,pos2);

                int temp ;
                temp = matrix[y][x];
                matrix[y][x] = matrix[pos3.getY()][pos3.getX()];
                matrix[pos3.getY()][pos3.getX()] = matrix[pos2.getY()][pos2.getX()];
                matrix[pos2.getY()][pos2.getX()] = matrix[pos1.getY()][pos1.getX()];
                matrix[pos1.getY()][pos1.getX()] = temp;
            }
        }

        return matrix;

    }

    private static Pos newPosition(int len,Pos pos) {

        int newX;
        int newY;

        newY = pos.getX();
        newX = -pos.getY() + len-1;
        return new Pos(newY,newX);
    }



    private static void swap(int[] nums,int num,int num1) {
        int temp;
        temp = nums[num];
        nums[num] = nums[num1];
        nums[num1] = temp;
    }


}
