package elyowon.ndb796;



import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;


/*
input
K1KA5CB7

*/
public class _28_자물쇠와열쇠 {

    public static void main(String[] args) {
        int[][] key = {{0,0,0},{1,0,0},{0,1,1}};
        int[][] lock = {{1,1,1},{1,1,0},{1,0,1}};

        boolean result = solution(key,lock);
        System.out.println(result);
    }

    public static boolean solution(int[][] key,int[][] lock) {

        int n = lock.length;
        int m = key.length;

        int[][] newLock = new int[n*3][m*3];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                newLock[i+n][j+n] = lock[i][j];
            }
        }

        for (int rotation = 0; rotation < 4; rotation++) {
            key = rotateMatrixBy90Degree(key);
            for (int x = 0; x < n * 2; x++) {
                for (int y = 0; y < n * 2; y++) {

                    for (int i = 0; i < m; i++) {
                        for (int j = 0; j < m; j++) {
                            newLock[x+i][y+j] += key[i][j];
                        }
                    }

                    if(check(newLock)) return true;
                    for (int i = 0; i < m; i++) {
                        for (int j = 0; j <m; j++) {
                            newLock[x+i][y+j] -= key[i][j];
                        }
                    }
                }
            }
        }
        return false;
    }

    public static boolean check(int[][] newLock) {

        int lockLength = newLock.length/3;
        for (int i = lockLength; i < lockLength * 2; i++) {
            for (int j = lockLength; j < lockLength * 2; j++) {
                if(newLock[i][j] != 1) {
                    return false;
                }
            }
        }
        return true;
    }

    private static int[][] rotateMatrixBy90Degree(int[][] key) {

        int n = key.length;
        int m = key[0].length;
        int[][] result = new int[n][m];
        for (int i = 0; i <n; i++) {
            for (int j = 0; j < n; j++) {
                result[j][n-i-1] = key[i][j];
            }
        }
        return result;
    }
}
