package me.elyowon.boj.그리디;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class 뒤집기 {

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
//        StringTokenizer st = new StringTokenizer(bf.readLine());
        String str = bf.readLine();

        ArrayList<String> strings = new ArrayList<>();

        int zeroCount = 0;
        int oneCount = 0;
        int ret = 0;
//
//        for(int i = 0; i<s.length; i++){
//            if(s[i] != s[i+1] && s[i] == '0'){
//                zeroCount+=1;
//            }
//            if(s[i] != s[i+1] && s[i] == '1') {
//                oneCount += 1;
//            }
//        }

        ret = zeroCount < oneCount ? zeroCount : oneCount;

        System.out.println(ret);
    }

}