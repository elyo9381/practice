package elyowon.leetcode.graph;


/**
 *
 * 블러드필 문제
 *
 */


public class leetcode_733_FloodFill {

    public int[][] floodFill(int[][] image,int sr,int sc,int newColor) {
        dfs(image,sr,sc,image[sr][sc],newColor);

        return image;
    }

    private void dfs(int[][] image,int sr,int sc,int color,int newColor) {
        if (sr < 0 || sc < 0 || sr >= image.length || sc >= image[0].length || image[sr][sc] != color) {
            return;
        }

        image[sr][sc] = newColor;
        dfs(image,sr,sc + 1,color,newColor);
        dfs(image,sr,sc - 1,color,newColor);
        dfs(image,sr + 1,sc,color,newColor);
        dfs(image,sr - 1,sc,color,newColor);

    }

}