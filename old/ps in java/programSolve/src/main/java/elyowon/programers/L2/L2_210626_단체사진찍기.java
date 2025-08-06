package elyowon.programers.L2;


import java.util.ArrayList;
import java.util.List;

/**
 *  네오 프로도 나란히 서길
 *  라이언 튜브에게서 적어도 3칸떨어지길
 */
public class L2_210626_단체사진찍기 {

    public static void main(String[] args) {
        String[] data = {"N~F=0", "R~T>2"};
        int solution = solution(2,data);
        System.out.println("solution = " + solution);
    }

    public static int solution(int n,String[] data) {
        int answer = 0;

        String s = "ACFJMNRT";
        char[] chars = s.toCharArray();


        List<List<Character>> result = new ArrayList<>();
        ArrayList<Character> curr = new ArrayList<>();
        boolean[] visited = new boolean[chars.length];

        comb(chars,n, 8,0, data,result, curr,visited);


        for (List<Character> characters : result) {
            if(isValidStr(data,characters)){
                answer++;
            }
        }
        System.out.println(answer);
        return answer;
    }

    private static void comb(char[] chars,int n,int target,int j,String[] data,List<List<Character>> result,ArrayList<Character> curr,boolean[] visited) {
        if( target == 0){
            ArrayList<Character> tmp = new ArrayList<>(curr);
            result.add(tmp);


            return ;
        }

        for (int i = 0; i < chars.length; i++) {
            if(visited[i] == true) continue;
            visited[i] = true;
            curr.add(chars[i]);
            comb(chars,n,target-1,i+1,data,result,curr,visited);
            curr.remove(curr.size()-1);
            visited[i] = false;

        }
    }

    private static boolean isValidStr(String[] datas,List<Character> tmp) {

        for (String data : datas) {
            char c1= data.charAt(0);
            char c2 = data.charAt(2);
            char op = data.charAt(3);
            int limit = (data.charAt(4)-'0');


            int range = Math.abs(tmp.indexOf(c1) - tmp.indexOf(c2))-1;

            if(op == '='){
                if(range != limit){
                    return false;
                }
            } else if( op == '<'){
                if(range >= limit){
                    return false;
                }
            } else if( op == '>'){
                if(range <= limit){
                    return false;
                }
            }

        }
        return true;
    }
}

