package elyowon.programers.prgmStudy.week_2;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class 주식가격Test {

    @Test
    public void test() throws Exception{
        //given
        주식가격 v = new 주식가격();
        //when
        int[] result1 = v.solution(new int[]{1,2,3,2,3});
        int[] result2 = v.solution(new int[]{5,4,3,2,1});
        //then
        for (int i : result2) {
            System.out.println("i = " + i);
        }
        assertArrayEquals(new int[]{4, 3, 1, 1, 0}, result1);
        assertArrayEquals(new int[]{1,1,1,1,0}, result2);
    }
}