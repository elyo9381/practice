package me.elyowon.programers.L2;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.PriorityQueue;

/**
 *  우선순위 블라블라 하지만
 *  모든 경우의수(순열)을 구해서
 *  max값을 구한다.
 *
 *  permutation을 설정해서 이를 진행할수있다.
 */
public class L2_210703_수식최대화 {

    public static long  answer = Long.MIN_VALUE;
    public static ArrayList<Long> numList = new ArrayList<>();
    public static ArrayList<String> opList = new ArrayList<>();


    public static String[] op = {"+","-","*"};
    public static String[] result = new String[3];
    public static boolean[] visited = new boolean[3];

    public static void main(String[] args) {
        String expression = "100-200*300-500+20";

        long solution = solution(expression);

    }
    public static long solution(String expression) {
        String n = "";
        for (int i = 0; i < expression.length(); i++) {
            char exp = expression.charAt(i);
            if (exp == '+' || exp == '-' || exp == '*') {
                opList.add(exp + "");
                numList.add(Long.parseLong(n));

                n = "";
            } else {
                n += exp;
            }
        }

        numList.add(Long.parseLong(n));
        permu(0,op.length);
        return answer;
    }

    private static void permu(int level,int target) {
        if (level == target) {
            solve();
            return;
        }

        for (int i = 0; i < op.length; i++) {
            if (!visited[i]) {
                visited[i] = true;
                result[level] = op[i];
                permu(level + 1,target);
                visited[i] = false;
            }
        }
    }
    private static void solve() {
        ArrayList<String> oper = new ArrayList<>();
        oper.addAll(opList);

        ArrayList<Long> num = new ArrayList<>();
        num.addAll(numList);

        for (int i = 0; i < result.length; i++) {
            String curOp = result[i];

            for (int j = 0; j < oper.size(); j++) {
                if (oper.get(j).equals(curOp)) {
                    long n1 = num.get(j);
                    long n2 = num.get(j + 1);
                    long res = cal(n1,n2,curOp);

                    num.remove(j + 1);
                    num.remove(j);
                    oper.remove(j);

                    num.add(j,res);
                    j--;
                }
            }
        }

        answer = Math.max(answer, Math.abs(num.get(0)));

    }

    private static long cal(long n1,long n2,String o) {

        long result = 0;
        switch (o) {
            case "+":
                result = n1 + n2;
                break;
            case "-":
                result = n1 - n2;
                break;
            case "*":
                result = n1 * n2;
                break;
        }

        return result;

    }
}