package me.elyowon.programers;

import java.util.*;

/**
 *
 * participant	             completion	         return
 * ["leo", "kiki", "eden"]	["eden", "kiki"]	"leo"
 *
 *
 * 1. participant을 배열 or 맵에 넣기
 * 2. completion을 배열or 맵에서 확인하고 값변경
 * 3. 혼자남거나 갑이 다른 하나를 반환
 *
 */

public class 완주하지못한선수_1 {


        public String solution(String[] participant, String[] completion) {
            String answer = "";
            HashMap<String, Integer> hm = new HashMap<>();
            for (String player : participant) hm.put(player, hm.getOrDefault(player, 0) + 1);
            for (String player : completion) hm.put(player, hm.get(player) - 1);

            for (String key : hm.keySet()) {
                if (hm.get(key) != 0){
                    answer = key;
                }
            }
            return answer;
        }
}
