package elyowon.leetcode.Queue;


import java.util.Stack;

public class leetcode_328_Queue {

    /**
     *
     * amortized 분활 상한 version
     *
     * 2개의 스택에서 데이터를 제거하지 않고
     * @param args
     */


    public static Stack<Integer> a = new Stack<Integer>();
    public static Stack<Integer> b = new Stack<Integer>();

    public static void main(String[] args) {


        enqueue(1);
        enqueue(2);
        enqueue(3);
        enqueue(4);
        enqueue(39);
        enqueue(9);


        while(true) {
            System.out.println("dequeue() = " + dequeue());
            if (b.size() == 0) break;
        }

    }

    private static void enqueue(int x) {
        a.add(x);
    }

    private static int dequeue() {
        if (0 < b.size()){
            return  b.pop();
        }
        moveToPopStack();
        return b.pop();
    }

    private static void moveToPopStack() {
        while(a.size() > 0){
            int tmp = a.pop();
            b.add(tmp);
        }
    }



}
