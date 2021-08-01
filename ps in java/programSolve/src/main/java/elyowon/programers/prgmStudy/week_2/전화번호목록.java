package elyowon.programers.prgmStudy.week_2;

import java.util.Arrays;


/**
 * 문자열알고리즘에서 a,b 비교하거나 둘 사이의 관계를 찾아야할때
 * a->b 만 생각치 말고 b->a 또한 생각해보길 바란다.
 *
 */
public class 전화번호목록 {

    public boolean solution(String[] phone_book) {

        Arrays.sort(phone_book);

        int length = phone_book.length;
        for(int i =0; i<length-1; i++){
            if(phone_book[i+1].startsWith(phone_book[i])) return false;
        }
        return true;

    }
}