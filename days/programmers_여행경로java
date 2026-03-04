import java.util.*;


class Solution {
    boolean found = false;

    public String[] solution(String[][] tickets) {


        Arrays.sort(tickets, (a,b) ->{
            if( a[0].equals(b[0]) ) return a[1].compareTo(b[1]);
            return a[1].compareTo(b[1]);
        });

        boolean[] visited = new boolean[tickets.length];
        ArrayList<String> route = new ArrayList();
        route.add("ICN");
        dfs("ICN",route,visited,tickets);
        return route.toArray(new String[0]);
    }

    private void dfs(String cur ,ArrayList<String> route ,
         boolean[] visited , String[][] tickets){

            if( route.size() == tickets.length+1){
                found = true;
                return ;
            }

            for(int i =0; i<tickets.length; i++){
                if( visited[i] || !tickets[i][0].equals(cur) ) continue;

                visited[i] = true;
                route.add(tickets[i][1]);
                dfs(tickets[i][1] , route, visited, tickets);
                if(found) return;
                visited[i] = false;
                route.remove(route.size()-1);
            }
        return ;
    }
}