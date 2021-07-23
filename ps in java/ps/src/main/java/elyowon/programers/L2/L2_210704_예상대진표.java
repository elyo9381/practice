package elyowon.programers.L2;



/**
 *
 * Integer.toBinaryString((a-1)^(b-1)).length();
 * ^ = XOR;
 * & = AND;
 * | = OR;
 * XOR를 이용하여 나온값은 공통된 부분을 지우고 다른부분은 1로 만들기때문에 이를 통해서
 * 공통된 연산을 수행할수있다.
 * XOR값을 String화 하고 이를 길이를 알게되면 최소 몇번 만에 만날수있는지 알게되는것이다.
 */
public class L2_210704_예상대진표 {


    public static void main(String[] args) {
        int result = solution(8,4,7);
        System.out.println(result);
    }

    public static int solution(int n,int a,int b){
        int answer  = 1;

        int left = 0;
        int right = 0 ;

        if( a > b){
            left = b;
            right = a;
        } else {
            left = a;
            right = b;
        }

        while(true){
            if( left % 2 != 0 && right - left == 1){
                break;
            }

            left = (left +1) /2;
            right = (right +1)/2;
            answer++;
        }

        return answer;
    }
}