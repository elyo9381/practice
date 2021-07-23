package elyowon.programers.L2;


import java.util.ArrayList;
import java.util.LinkedList;

/**
 * 조합으로 풀려고 햇으나 실패
 * 탐색으로 풀어야했다 => 왜? 맨해튼거리가 2일때 대각선을 체크해야하므로
 *
 * x 일때는 bfs탐색 안하면 된다.
 * 매번 거리를 측정해서 체크하면된다.
 */
public class L2_210708_거리두기확인하기 {

    public static int[] dx = {-1,1,0,0};
    public static int[] dy = {0,0,-1,1};

    public int[] solution(String[][] places) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        for(String[] palce : places){
            result.add(DistanceProper(palce));
        }
        return result.stream().mapToInt(i->i).toArray();
    }

    public int DistanceProper(String[] place){

        ArrayList<String> graph = new ArrayList<>();

        int r = place.length;
        int c = place[0].length();

        for(int i = 0; i<place.length; i++){
            graph.add(place[i]);
        }

        boolean check = true;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                boolean[][] visited = new boolean[r][c];
                if(place[i].charAt(j)=='P'){
//                    if(!bfs(place,i,j,visited)){
//                        check = false;
//                    }
                    visited[i][j] = true;
                    if(!dfs(place,i,j,0,visited)){
                        check = false;
                    }
                }
            }
        }

        return check == true ? 1 : 0;
    }


    private boolean dfs(String[] board,int x ,int y ,int count, boolean[][] visited){
        if (count > 2) return true;
        if (count > 0 && count <= 2 && board[x].charAt(y) == 'P'){
            //2칸 범위내에 다른 응시자가 있을 경우 거리두기 미준수로 0처리

            return false;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            //배열 범위 밖으로 초과하는지 여부 검사, 파티션으로 분리되어 있는 경우 상관 없음.
            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && board[nx].charAt(ny) != 'X') {
                if (visited[nx][ny]) continue; //이미 방문한 곳일 경우 생략
                visited[nx][ny] = true;
                dfs(board, nx, ny, count + 1, visited);
                visited[nx][ny] = false;
            }
        }
        return true;
    }

    private boolean bfs(String[] board,int i,int j,boolean[][] visited) {

        LinkedList<int[]> q = new LinkedList<>();

        visited[i][j] = true;
        q.add(new int[]{i,j,0});

        while(!q.isEmpty()){
            int[] poll = q.poll();
            int x = poll[0];
            int y = poll[1];
            int dis = poll[2];


            for(int k = 0; k<4; k++){
                int nx = dx[k] + x;
                int ny = dy[k] + y;

                if( nx < 0 || nx >= board.length
                        || ny <0 || ny >= board[0].length()
                        || visited[nx][ny]
                        || board[nx].charAt(ny) == 'X')
                    continue;

                if( board[nx].charAt(ny) == 'P' && dis <= 1){
                    return false;
                }
                visited[nx][ny] = true;
                q.add(new int[]{nx,ny,dis+1});
            }
        }
        return true;
    }
}