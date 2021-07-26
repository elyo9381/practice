package elyowon.programers.prgmStudy.week_1;


import java.util.HashSet;
import java.util.LinkedList;

/**
 *
 */
public class L3_210714_방문길이 {
    // 게임 캐릭터가 처음 걸어본 길의 길이 return
    HashSet<String> set = new HashSet<>();

    public int solution(String dirs) {

        LinkedList<int[]> q = new LinkedList<int[]>();

        int idx = 0;
        int x = 0;
        int y = 0;
        q.add(new int[]{5,5});

        while (!q.isEmpty()) {
            if(idx == dirs.length())break;
            int[] poll = q.poll();
            x = poll[0];
            y = poll[1];

            int[] move = checkPos(dirs,idx);
            idx++;

            int nx = x + move[0];
            int ny = y + move[1];

            if (nx < 0 || ny < 0 || nx > 10 || ny > 10){
                // nx -= move[0];
                // ny -= move[1];
                q.add(new int[]{x,y});
                continue;
            }

            set.add(String.valueOf(x + "" + y + "" + nx + "" + ny));
            set.add(String.valueOf(nx + "" + ny + "" + x + "" + y));
            q.add(new int[]{nx,ny});
        }
        return set.size() / 2;
    }

    private int[] checkPos(String dirs,int idx) {
        char c = dirs.charAt(idx);
        int[] result = new int[2];
        if (c == 'U') {
            result[0] = -1;
            result[1] = 0;
        }
        if (c == 'D') {
            result[0] = 1;
            result[1] = 0;
        }
        if (c == 'L') {
            result[0] = 0;
            result[1] = -1;
        }
        if (c == 'R') {
            result[0] = 0;
            result[1] = 1;
        }
        return result;
    }
}