package me.elyowon.boj.그리디;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj2613 {

    /**
     * 구간을 나누는데 그룹이 없을수도 있다
     * 이러하면 이전 그룹에서 하나를 줄이고 본래 그룹자리에 하나를 늘려
     * 최소 하나라도 들어가게 해야한다.
     *
     * 그것을 countMarble을 통해서 구슬의 갯수를 셌다.
     */

    static int n, m, result;
    static int[] marble;
    static int[] countMarble;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = stoi(st.nextToken());
        m = stoi(st.nextToken());

        marble = new int[n];
        countMarble = new int[m + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            marble[i] = stoi(st.nextToken());
        }

        parametric();
        System.out.println(result);
        noZeroGroup();

        for (int i = 0; i < m; i++) {
            System.out.print(countMarble[i] + " ");
        }
    }

    private static void parametric() {
        int left = 0;
        int right = n * 100;

        while (left < right) {
            int mid = (left + right) >> 1;
            if (isPossible(mid)) {
                result = mid;
                right = mid;
            } else {
                left = mid + 1;
            }
        }
    }

    private static boolean isPossible(int mid) {
        int count = 0;
        int tempSum = 0;
        int[] tempCount = new int[m + 1];
        for (int i = 0; i < n; i++) {
            if (marble[i] > mid) {
                return false;
            }
            if (tempSum + marble[i] > mid) {
                tempSum = marble[i];
                count++;
            } else {
                tempSum += marble[i];
            }
            if (count >= m) {
                return false;
            }
            tempCount[count]++;
        }
        countMarble = tempCount;
        return true;

    }

    private static void noZeroGroup() {
        int index;
        for (int i = 0; i < m; i++) {
            if (countMarble[i] == 0) {
                index = i - 1;
                countMarble[i]++;
                while (true) {
                    if (countMarble[index] == 1) {
                        index--;
                        continue;
                    }
                    break;
                }
                countMarble[index]--;
            }
        }
    }

    private static int stoi(String input) {
        return Integer.parseInt(input);
    }
}