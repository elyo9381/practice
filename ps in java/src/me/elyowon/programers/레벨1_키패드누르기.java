package me.elyowon.programers;


/**
 *
 */
public class 레벨1_키패드누르기 {


    public static void main(String[] args) {
        int[] numbers = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};

        String hand = "right";
        String s = solution(numbers,hand);

        System.out.println("s = " + s);
    }

    public static String solution(int[] numbers,String hand) {
        String answer = "";
        int leftIndex = 10;
        int rightIndex = 12;

        for (int number : numbers) {
            if (number == 1 || number == 4 || number == 7) {
                answer += "L";

                leftIndex = number;
            } else if (number == 3 || number == 6 || number == 9) {
                answer += "R";

                rightIndex = number;
            } else {
                int leftLength = getLength(leftIndex,number);
                int rightLength = getLength(rightIndex,number);

                if (leftLength > rightLength) {
                    answer += "R";
                    rightIndex = number;
                } else if (leftLength < rightLength) {
                    answer += "L";
                    leftIndex = number;
                } else {
                    if (hand.equals("right")) {
                        answer += "R";
                        rightIndex = number;
                    } else {
                        answer += "L";
                        leftIndex = number;
                    }
                }
            }
        }
        return answer;
    }

    public static int getLength(int index,int number) {

            index = (index == 0) ? 11 : index;
            number = (number == 0) ? 11 : number;

            int x = (index - 1) / 3;
            int y = (index - 1) % 3;
            int numberX = number / 3;
            int numberY = 1;

            return Math.abs(x-numberX) + Math.abs(y-numberY);
        }
}
