package elyowon.programers.L1;


/**
 * 2021.06.21
 *
 * 정규표현식
 * 그룹 * | -> 또는
 * () -> 그룹
 * [] -> 문자셋, 괄호안의 어떤 문자든
 * [^] -> 부정 문자셋, 괄호안의 어떤 문자가 아닐때
 * (?:) -> 찾지만 기억하지는 않음
 *
 *
 * Quanrifiers
 * ? -> 없거나 있거나
 * * -> 없거나 있거나 많거나
 * + -> 하나 또는 많이
 * {n} -> n번 반복
 * {min, } 최소
 * {min,max} 최소 그리고 최대
 *
 * Boundary - type
 * \b -> 단어 경계
 * \B -> 단어 경계가 아님
 * ^ 문장의 시작
 * $ 문장의 끝
 *
 *
 * Character classes
 * \ -> 특수문자가 아닌 문자
 * . 어떤글자
 * \d -> digit 숫자
 * \D -> digit 숫자 아님
 * \w -> word 문자
 * \W -> word문자 아님
 * \s -> space공백
 * \S -> space공백 아님
 */
public class 레벨1_신규아이디추천 {


    public String solution(String new_id) {
        String id = new_id.toLowerCase();
        id = id.replaceAll("[^-_.a-z0-9]","");
        id = id.replaceAll("[.]{2,}",".");
        id = id.replaceAll("^[.]|[.]$","");

        if(id.equals("")) id +="a";

        if(id.length() >= 16){
            id = id.substring(0,15);
            id = id.replaceAll("^[.]|[.]$","");
        }
        if(id.length() <= 2){
            while(id.length() < 3)
                id += id.charAt(id.length() -1 );
        }


        return id;
    }
}
