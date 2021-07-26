package elyowon.programers.L2;


import java.util.*;

/**
 *
 */
public class L2_210629_오픈채팅방 {

    static class User {
        public String op;
        public String userId;

        User(String op,String userId) {
            this.op = op;
            this.userId = userId;
        }
    }

    public static String[] solution(String[] record) {

        Queue<User> q = new LinkedList<>();
        HashMap<String, String> hs = new HashMap<String, String>();

        for (String s : record) {
            String[] s1 = s.split("\\s+");
            if(s.contains("Enter")){
                HashPut(hs,s);
            } else if (s.contains("Change")){
                HashPut(hs,s);
            }
        }

        for (String s : record) {
            String[] s1 = s.split(" ");
            String op = s1[0];
            String id = s1[1];
            q.add(new User(op,id));
        }

        ArrayList<String> strList = new ArrayList<>();
        while (!q.isEmpty()) {
            User poll = q.poll();
            if (poll.op.equals("Enter")) {

                strList.add(hs.get(poll.userId) + "님이 들어왔습니다.");
            } else if (poll.op.equals( "Leave")) {
                strList.add(hs.get(poll.userId) + "님이 나갔습니다.");
            }
        }


        int idx = 0;
        String[] answer = new String[strList.size()];
        for (String s : strList) {
            answer[idx++] = s;
        }
        return answer;
    }

    public static void main(String[] args) {
        String[] record = {"Enter uid1234 Muzi","Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
        String[] solution = solution(record);

        for (String s : solution) {
            System.out.println("s = " + s);
        }
    }


    private static void HashPut(HashMap<String, String> hs,String s) {
        String[] s1 = s.split("\\s+");
        String id = s1[1];
        String name = s1[2];
        if (hs.get(id) != null) {
            hs.replace(id,name);
            return;
        }
        hs.put(id,name);
    }
}
//if(op == "Enter"){
//               q.add(User);
//            } else if (op == "Leave"){
//
//            } else {
//
//            }

