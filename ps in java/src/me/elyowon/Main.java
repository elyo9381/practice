package me.elyowon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/***
 * 문자열로 받고 문자사용한다.
 * int가 필요하면 integer.parseInt를 통해서 타입변환한다.
 * BufferedReader(new InputStreamReader(System.in)); 입력 버퍼 동적할당
 * StringTokenizer(br.readLine());을 통해서 실질적인 입력을 받는다.
 *
 */

public class Main {


    public static void main(String[] args) throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        int N = Integer.parseInt(st.nextToken());	// 물이 새는 곳의 개수
        int L = Integer.parseInt(st.nextToken());	// 테이프 길이

        int min = 0;	// 필요한 테이프의 최소 개수
        int[] arr = new int[N];

        st = new StringTokenizer(bf.readLine());
        for(int i=0; i<arr.length; i++)
            arr[i] = Integer.parseInt(st.nextToken());

        //현재 물이 샌곳에 테이프를 붙였을때, 테이프가 영향을 미치는 범위
        int tapeRange = (int)(arr[0] - 0.5 + L);
        min ++;

        Arrays.sort(arr);

        for(int i=1; i<arr.length; i++) {
            if (tapeRange < (int)(arr[i] + 0.5)){
                tapeRange = (int)(arr[i] - 0.5 + L);
                min ++;
            }
        }

        System.out.println(min);
        bf.close();
    }

}

