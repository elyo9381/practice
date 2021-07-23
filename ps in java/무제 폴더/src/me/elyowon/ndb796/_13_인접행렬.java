package me.elyowon.ndb796;

public class _13_인접행렬 {

    /**
     * 인접행렬은 2차원 리스트를 이용해 표현
     * */

    private static final int INF = 987654321;

    private static int[][] graph = {
            {0,7,5},
            {7,0,INF},
            {5,INF,0}
    };

    public static void main(String[] args) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.println(graph[i][j] + " ");
            }
            System.out.println();
        }
    }

}