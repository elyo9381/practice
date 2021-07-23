//package me.elyowon.leetcode.algorithm;
//
//
//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.ArrayList;
//import java.util.LinkedList;
//import java.util.Queue;
//import java.util.Scanner;
//
//class Node {
//    int valid;
//    int[] children;
//    int pi;
//    ArrayList<Integer> indexes;
//    Node() {
//        valid=-1;
//        children = new int[26];
//        for(int i=0; i<26; i++) {
//            children[i]=-1;
//        }
//        pi=-1;
//        indexes = new ArrayList<Integer>();
//    }
//}
//
//
//
//public class Aho_Corasick {
//    static ArrayList<Node> trie = new ArrayList<>();
//    static int init() {
//        Node x = new Node();
//        trie.add(x);
//        return (int)trie.size()-1;
//    }
//    static void add(int node, String s, int index, int string_index) {
//        if(index==s.length()) {
//            trie.get(node).valid=string_index;
//            return;
//        }
//        int c = s.charAt(index)-'a';
//        if(trie.get(node).children[c]==-1) {
//            int next=init();
//            trie.get(node).children[c]=next;
//        }
//        add(trie.get(node).children[c], s, index+1, string_index);
//    }
//    public static void main(String args[]) {
//        Scanner sc = new Scanner(System.in);
//        int root = init();
//        int n = sc.nextInt();
//        String[] a = new String[n];
//        for(int i=0; i<n; i++) {
//            a[i]=sc.next();
//            add(root, a[i], 0, i);
//        }
//        Queue<Integer> q = new LinkedList<>();
//        trie.get(root).pi=root;
//        q.add(root);
//        while(!q.isEmpty()) {
//            int cur = q.remove();
//            for(int i=0; i<26; i++) {
//                int next = trie.get(cur).children[i];
//                if(next==-1) continue;
//                if(cur==root) {
//                    trie.get(next).pi=root;
//                } else {
//                    int x = trie.get(cur).pi;
//                    while(x!=root && trie.get(x).children[i]==-1) {
//                        x=trie.get(x).pi;
//                    }
//                    if(trie.get(x).children[i]!=-1) {
//                        x=trie.get(x).children[i];
//                    }
//                    trie.get(next).pi=x;
//                }
//                int pi = trie.get(next).pi;
//                trie.get(next).indexes = new ArrayList<>(trie.get(pi).indexes);
//                if(trie.get(next).valid!=-1) {
//                    trie.get(next).indexes.add(trie.get(next).valid);
//                }
//                q.add(next);
//            }
//        }
//        int m = sc.nextInt();
//        while(m-->0) {
//            String s = sc.next();
//            int node =root;
//            boolean ok = false;
//            for (int i=0; i<s.length(); i++) {
//                int c = s.charAt(i) - 'a';
//                while(node!=root && trie.get(node).children[c]==-1) {
//                    node = trie.get(node).pi;
//                }
//                if(trie.get(node).children[c] !=-1) {
//                    node = trie.get(node).children[c];
//                }
//                if(trie.get(node).indexes.size()>0) {
//                    ok = true;
//                }
//            }
//            System.out.println(ok? "YES" : "NO");
//        }
//    }
//}
//
package me.elyowon.leetcode.algorithm;



import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;


public class Aho_Corasick {

    static int N, Q;


    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        TrieNode root = new TrieNode();

        N = Integer.parseInt(br.readLine());
        while (N-- > 0) root.insert(br.readLine());

        root.makeFail();

        Q = Integer.parseInt(br.readLine());
        while (Q-- > 0) {
            if (root.search(br.readLine())) System.out.println("YES");
            else System.out.println("NO");
        }
    }
}

class TrieNode {
    static Node root = new Node();

    static class Node{

        HashMap<Character, Node> children = new HashMap<>();
        boolean isEnd = false;
        Node fail = null;

        char v;
        String word = null;

        public Node isChildren(Character c){

            Node it = children.get(c);
            if(it == null) return null;
            return it;
        }

        public Node create(Character c) {
            Node it = children.get(c);
            if (it == null) {
                it = new Node();
                it.v = c;
                it.fail = this;
                children.put(c,it);
                return it;
            }
            return it;
        }


    }
    public static void insert(String word) {
        var node = root;
        // 9 ms: for (int i = 0; i < word.length(); i++) {
        // 1 ms: for (int i = word.length() - 1; i >= 0; i--) {
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            var next = node.create(c);
            node = next;
        }
//        node.word = word; // the last node contains teh whole word
        node.isEnd =true;
    }

    static void makeFail() {
        Queue<Node> q = new LinkedList<>();
        root.fail = root;
        q.offer(root);
        while (!q.isEmpty()) {
            Node current = q.poll();
            for (Character c  = 'a'; c <= 'z'; c++) {
                if (current.isChildren(c) == null) continue;

                Node next = current.isChildren(c);
                if (current == root) next.fail = root;
                else {
                    Node dest = current.fail;
                    while (dest != root && dest.isChildren(c) == null)
                        dest = dest.fail;
                    if (dest.isChildren(c)!= null) dest = dest.isChildren(c);
                    next.fail = dest;
                }

                q.offer(next);
            }
        }
    }


    static boolean search(String s) {
        Node current = root;
        for (int i = 0; i < s.length(); i++) {
            Character c = s.charAt(i);
            while (current != root && current.isChildren(c) == null)
                current = current.fail;
            if (current.isChildren(c)!=null) current = current.isChildren(c);
            if (current.fail.isEnd) return true;
            if (current.isEnd) return true;
        }
        return false;
    }

}


//    void insert(String s) {
//        Node current = root;
//        for (int i = 0; i < s.length(); i++) {
//            char c = s.charAt(i);
//            if (!current.hasChild(c))
//                current.children[c - 'a'] = new Node();
//            current = current.getChild(c);
//        }
//        current.isEnd = true;
//    }
//
//    void makeFail() {
//        Queue<Node> q = new LinkedList<>();
//        root.fail = root;
//        q.offer(root);
//        while (!q.isEmpty()) {
//            Node current = q.poll();
//            for (char c = 'a'; c <= 'z'; c++) {
//                if (!current.hasChild(c)) continue;
//
//                Node next = current.getChild(c);
//                if (current == root) next.fail = root;
//                else {
//                    Node dest = current.fail;
//                    while (dest != root && !dest.hasChild(c))
//                        dest = dest.fail;
//                    if (dest.hasChild(c)) dest = dest.getChild(c);
//                    next.fail = dest;
//                }
//
//                q.offer(next);
//            }
//        }
//    }
//

//    static class Node {
//
//    }
//}
