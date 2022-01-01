package elyowon.programers.prgmStudy.week_4;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class 정수삼각형Test {

    @Test
    public void test() throws Exception{
        //given
        정수삼각형 v = new 정수삼각형();
        //when
        int[][] tri = {{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};

        int solution = v.solution(tri);
        //then
        System.out.println("solution = " + solution);
    }
}