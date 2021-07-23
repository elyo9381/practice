package elyowon.programers.prgmStudy.week_2;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class 올바른괄호Test {

    @Test
    public void  test() throws Exception{
        //given
        올바른괄호 s = new 올바른괄호();
        //when
        boolean result1 = s.solution("))((");
        boolean result2 = s.solution("(())");
        boolean result3 = s.solution("(())(");
        //then
        assertEquals(false, result1);

        assertEquals(true, result2);
        assertEquals(false, result3);
    }

}