package elyowon.ndb796;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


/*
* input
* 5
* 2 3 1 2 2
* */
public class _24_모험가길드 {

    public static int n;
    public static ArrayList<Integer> arrayList = new ArrayList<Integer>();


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n; i++) {
            arrayList.add(Integer.parseInt(st.nextToken()));
        }


        Collections.sort(arrayList);

        int result = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            count+=1;
            if(count >= arrayList.get(i)){
                result +=1;
                count = 0;
            }
        }

        System.out.println(result);

    }
}
