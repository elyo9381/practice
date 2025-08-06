package elyowon.programers.prgmStudy.week_3;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class 타켓넘버Test {


    @Test
    public void test() throws Exception{
        //given
        타켓넘버 v = new 타켓넘버();
        int[] numbers = {1,1,1,1,1};
        int target = 3;
        //when

        int solution = v.solution(numbers,target);
        System.out.println("solution = " + solution);

        //then
    }

}