package me.elyowon.ndb796;


import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class _22_효율적인화폐구성 {

    /**
     *
     * ai개의 동전을 가지고 k를 만드는게 최소의 갯수이다.
     * 생각해보면 k를 만드는것은 정수배인것이 최소일것이다. 막섞으면 최소가 나오지 않으니
     * 그러므로 정수배를 찾아야한다.
     *
     * 자 그러면 탐색,dp등의 방법으로 정수배를 찾을수있는데
     * 혹시나 섞였을때 최소가 나올수도 있으니 min을 이용해서 비교 하도록 하자
     * 그렇다면 인덱스가 존재하므로 i-k은 k의 배수이고 이를 체크하기 위해서 1을 더한다.
     * 또한 min(a[i],a[i-k[j]]+1)을 통해 비교하며 최소갯수를 찾는다
     *
     */

    private static int solution(int[] k,int m) {
        int[] a = new int[m+1];

        Arrays.fill(a,10001);
        a[0] = 0;

        for (int i = 0; i < k.length; i++) {
            for (int j = k[i]; j < m; j++) {
                a[j] = Math.min(a[j], a[j - k[i]]+1);
            }
        }

        if(a[m] == 10001)
            a[m] = -1;

        return a[m];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt((st.nextToken()));
        int m = Integer.parseInt((st.nextToken()));
        int[] k = new int[n];

        for(int i = 0; i<k.length; i++){
            k[i] = Integer.parseInt(br.readLine());
        }
        bw.write(solution(k,m) + "\n");

        br.close();
        bw.close();

    }
}