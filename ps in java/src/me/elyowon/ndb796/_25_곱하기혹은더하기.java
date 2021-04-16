package me.elyowon.ndb796;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;


/*
input
02984

*/
public class _25_곱하기혹은더하기 {

    public static int n;
    public static ArrayList<Integer> arrayList = new ArrayList<Integer>();


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        String str = st.nextToken();

        long result = str.charAt(0) - '0';

        for (int i = 1; i < str.length(); i++) {
            int num = str.charAt(i) - '0';
            if(num <= 1 || result <=1){
                result +=num;
            }
            else{
                result *=num;
            }
        }
        System.out.println(result);
    }
}
