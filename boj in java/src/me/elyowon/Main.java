package me.elyowon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());

        String line = bf.readLine();
        System.out.println("line = " + line);

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

