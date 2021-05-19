package me.elyowon.leetcode.tree;


import java.util.HashMap;
import java.util.Map;

/**
 * leetcode 208
 * <p>
 * <p>
 * map.entrySet().stream().forEach(entry-> {
 * System.out.println("[key]:" + entry.getKey() + ", [value]:"+entry.getValue());
 * });
 * <p>
 * // Stream 사용 - 내림차순
 * map.entrySet().stream().sorted(Map.Entry.comparingByKey()).forEach(entry-> {
 * System.out.println("[key]:" + entry.getKey() + ", [value]:"+entry.getValue());
 * });
 * <p>
 * // Stream 사용 - 오름차순
 * map.entrySet().stream().sorted(Map.Entry.comparingByKey(Comparator.reverseOrder())).forEach(entry-> {
 * System.out.println("[key]:" + entry.getKey() + ", [value]:"+entry.getValue());
 * });
 */


public class Trie {

    TrieNode head;

    public Trie() {
        head = new TrieNode();
    }

    public void addWord(String word) {
        if (word == null) {
            return;
        }
        TrieNode node = head;
        for (char ch : word.toCharArray()) {
            if (!node.children.containsKey(ch)) {
                node.children.put(ch,new TrieNode());
            }
            node = node.children.get(ch);
        }
        node.isEnd = true;
//        node.word = c
    }

    public boolean search(String word) {
        if (word == null) {
            return false;
        }

        TrieNode node = head;
        for (char ch : word.toCharArray()) {
            if (!node.children.containsKey(ch)) {
                return false;
            }
            node = node.children.get(ch);
        }
        return node.isEnd;
    }

    public boolean startWith(String prefix) {
        if (prefix == null) {
            return false;
        }
        TrieNode node = head;
        for (char ch : prefix.toCharArray()) {
            if (!node.children.containsKey(ch)) {
                return false;
            }
            node = node.children.get(ch);
        }
        return true;
    }


    public boolean searchTwo(String word) {
        return findDot(word,0,head);
    }

    public boolean findDot(String word,int index,TrieNode now) {
        if (index == word.length()) {
            if (now.children.size() == 0)
                return true;
            else
                return false;
        }

        Character ch = word.charAt(index);
        if (now.children.containsKey(ch)) {
            if (index == word.length() - 1 && now.children.get(ch).isEnd) {
                return true;
            }
            return findDot(word,index + 1,now.children.get(ch));
        } else if (ch == '.') {
            boolean result = false;

//            now.children.entrySet().stream().forEach(entry -> {
//                if (index == word.length() - 1 && entry.getValue().isEnd) {
//                    return true;
//                }
//
//                //if any path is true, set result to be true;
//                if (findDot(word,index + 1,entry.getValue())) {
//                    result = true;
//                }
//            });

            for (Map.Entry<Character, TrieNode> child : now.children.entrySet()) {
                if (index == word.length() - 1 && child.getValue().isEnd) {
                    return true;
                }

                //if any path is true, set result to be true;
                if (findDot(word,index + 1,child.getValue())) {
                    result = true;
                }
            }
            return result;
        } else {
            return false;
        }
    }


    class TrieNode {

        Map<Character, TrieNode> children;
        boolean isEnd = false;
        String word = null;
//
        public TrieNode() {
            children = new HashMap();
        }
    }

}


