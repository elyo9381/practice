package elyowon.programers.prgmStudy.week_1;


import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 *  스킬트리에 스킬이의 단어를 포함하는지 valueOf를 사용해서 잘 알수있었으나.
 *  스킬이 기준이 아닌 스킬트리에 기준을두어 삭제한다는 점을 생각하지 못했다.
 *  그래서 못풀었다.
 *  나는 스킬에 존재하는지만 체크하고  if문으로 거를려고 했더니 매우 복잡하였다.
 */
public class L2_210714_스킬트리 {

    // 프로그래머스 제출한 코드 startWith의 방법으로도 풀이가 가능함을 생각하자
    public int solution2(String skill, String[] skill_trees) {
        int answer = 0;
        for (String tree : skill_trees) {
            String temp = "";
            for (int i = 0; i < tree.length(); i++) {
                String t = String.valueOf(tree.charAt(i));
                if (skill.contains(t)) {temp += t;}
            }
            if(skill.startsWith(temp)) answer++;
        }
        return answer;
    }

    public int solution(String skill, String[] skill_trees) {
        int answer = 0;

        int index = 0;
        while(true) {
            String skill_tree = skill_trees[index];
            String skill_clone = new String(skill_tree);
            int size = skill_tree.length();
            for (int i =0; i < size; i++) {
                String oneSkill = String.valueOf(skill_clone.charAt(i));
                if (!skill.contains(oneSkill)) {
                    skill_tree = skill_tree.replace(oneSkill, "");
                }
            }
            if (skill.indexOf(skill_tree) == 0) {
                answer++;
            }
            index++;
            if(index == skill_trees.length) break;
        }

        return answer;
    }

    /**
     *
     * 타인의 코드이다.
     * 스킬에 기준이 아닌 스킬트리에 기준을 맞춰 해당 스킬트리를 변경하는 코드이다.
     * 정규표현식으로 스킬트리를 고친다는것을 이해하자
     *
     * @param skill
     * @param skill_trees
     * @return
     */
    public int solution1(String skill, String[] skill_trees){
        int answer = skill_trees.length;

        for(int i =0; i< skill_trees.length; i++){
            if(skill.indexOf(skill_trees[i].replaceAll("[^"+skill+"]",""))!=0){
                answer--;
            }
        }
        return answer;
    }
}