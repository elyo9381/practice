package elyowon.programers.L1;


/**
 *
 */
public class L1_210626_문자열을정수로바꾸기 {
    public int solution(String s) {
        int answer = 0;

        answer = s.charAt(0) == '-' ?
                -Integer.parseInt(s.substring(1,s.length())) :
                Integer.parseInt(s.substring(0,s.length()));

        return answer;
    }

}

