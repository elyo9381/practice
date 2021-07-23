package elyowon.programers.prgmStudy.week_2;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class 완주하지못한선수Test {


    @Test
    public void test() throws Exception{
        //given
        완주하지못한선수 a = new 완주하지못한선수();
        String[] participant = new String[]{"marina", "josipa", "nikola", "vinko", "filipa"};
        String[] completion = new String[]{"josipa", "filipa", "marina", "nikola"};
        //when
        String result = a.solution(participant,completion);
        //then
        assertEquals("vinko",result);
    }

}