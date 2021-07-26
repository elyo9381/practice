package elyowon.programers.prgmStudy.week_2;

import java.util.*;
import java.util.stream.Collectors;

/**
 * 규칙 1: 한 메서드에 오직 한 단계의 들여쓰기만 한다.
 * 규칙 2: else 예약어를 쓰지 않는다.
 * 규칙 3: 모든 원시값과 문자열을 포장한다.
 * 규칙 4: 한 줄에 점을 하나만 찍는다.
 * 규칙 5: 줄여쓰지 않는다(축약 금지).
 * 규칙 6: 모든 엔티티를 작게 유지한다.
 * 규칙 7: 3개 이상의 인스턴스 변수를 가진 클래스를 쓰지 않는 다.
 * 규칙 8: 일급 콜렉션을 쓴다.
 * 규칙 9: 게터/세터/프로퍼티를 쓰지 않는다.
 */

class FinishPlayers {
    List<Player> completions;
    List<Player> participants;
    HashMap<String, Integer> hashMap = new HashMap<>();

    public FinishPlayers(List<Player> completions,List<Player> participants) {
        this.completions = completions;
        this.participants = participants;
    }

    public void computeFinisher() {
        for (Player participant : this.participants) {
            hashMap.put(participant.getPlayer(),hashMap.getOrDefault(participant.getPlayer(),(0)) + 1);
        }
        for (Player completion : this.completions) {
            hashMap.put(completion.getPlayer(),hashMap.get(completion.getPlayer()) - 1);
        }
    }

    public String notFinishPlayer() {
        String result = "";
        for (Map.Entry<String, Integer> entry : hashMap.entrySet()) {
            if (entry.getValue() > 0)
                result = entry.getKey();
        }
        return result;
    }
}


class Player {
    String player;

    public Player(String player) {
        this.player = player;
    }

    public String getPlayer() {
        return player;
    }
}

public class 완주하지못한선수 {

    public String solution(String[] participant,String[] completion) {

        List<Player> completions = Arrays.stream(completion).map(Player::new).collect(Collectors.toList());
        List<Player> participants = Arrays.stream(participant).map(Player::new).collect(Collectors.toList());

        FinishPlayers finishPlayers = new FinishPlayers(completions,participants);

        finishPlayers.computeFinisher();

        return finishPlayers.notFinishPlayer();
    }
}