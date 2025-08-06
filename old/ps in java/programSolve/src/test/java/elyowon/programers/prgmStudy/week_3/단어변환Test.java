package elyowon.programers.prgmStudy.week_3;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class 단어변환Test {

    @Test
    public void test() throws Exception{
        //given
        단어변환 v = new 단어변환();
        String begin  = "hit";
        String target = "cog";

        String[] words = {"hot","dot","dog","lot","log","cog"};
        //when
        int result = v.solution(begin,target,words);
        System.out.println("result = " + result);

        //then
    }

}