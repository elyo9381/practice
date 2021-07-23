package elyowon.ndb796;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.SQLOutput;
import java.util.ArrayList;
import java.util.StringTokenizer;


/*
input
123402

*/
public class _26_럭키스트레이트 {


    private static int summary;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        String str = st.nextToken();

        for(int i = 0; i<str.length()/2; i++){
            summary += str.charAt(i) - '0';
        }

        for (int i = str.length()/2; i < str.length(); i++) {
            summary -= str.charAt(i) - '0';
        }

        if(summary == 0) System.out.println("LUCKY");
        else System.out.println("READY");
    }
}
