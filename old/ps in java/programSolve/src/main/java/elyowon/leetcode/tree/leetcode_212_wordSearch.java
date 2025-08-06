package elyowon.leetcode.tree;


import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 *
 *
 *
 */

public class leetcode_212_wordSearch {

    public List<String> findWords(char[][] board,String[] words) {
        List<String> res = new ArrayList<>();
        TrieNode root = buildTrie(words);
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                dfs(board,i,j,root,res);
            }
        }
        return res;
    }

    private void dfs(char[][] board,int i,int j,TrieNode p,List<String> res) {
        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length) {
            return;
        }

        char c = board[i][j];
        if (c == '#' || !p.children.containsKey(c)) return;
        p = p.children.get(c);
        if (p.word != null) {
            res.add(p.word);
            p.word = null;
        }

        board[i][j] = '#';
        dfs(board,i - 1,j,p,res);
        dfs(board,i,j - 1,p,res);
        dfs(board,i + 1,j,p,res);
        dfs(board,i,j + 1,p,res);
        board[i][j] = c;


    }

    public TrieNode buildTrie(String[] word) {
        TrieNode root = new TrieNode();
        for (String w : word) {
            TrieNode node = root;
            for (char ch : w.toCharArray()) {
                if (!node.children.containsKey(ch)) {
                    node.children.put(ch,new TrieNode());
                }
                node = node.children.get(ch);
            }
            node.isEnd = true;
            if (node.isEnd) {
                node.word = w;
            }
        }
        return root;
    }

    class TrieNode {

        Map<Character, TrieNode> children;
        boolean isEnd = false;
        String word = null;

        public TrieNode() {
            children = new HashMap();
        }
    }
}

/**
 *
 * leetcode 1ms , 8ms 코드
 * 트라이노드에서 parent 노드 구현 (why) : 존재하는 단어를 검색후 해당 노드 삭제해야하는데 this의 parent를 모르면
 * 다시 검색해와야하기 때문에
 * map 검색 구현, 그리고 hashMap.get사용(containsKey() 느림)
 *
 *
 */
class Solution {
    class TrieNode {
        TrieNode parent = null;
        HashMap<Character, TrieNode> children = new HashMap<>();

        char v;
        String word = null;

        public TrieNode getOrCreateChild(Character c) {
            TrieNode it = children.get(c);
            if (it == null) {
                it = new TrieNode();
                it.v = c;
                it.parent = this;
                children.put(c, it);
            }
            return it;
        }
    }

    int m, n;
    TrieNode root;
    List<String> result;

    public List<String> findWords(char[][] board, String[] words) {
        result = new ArrayList<>();
        m = board.length;
        n = board[0].length;

        root = new TrieNode();
        for (String word : words) {
            addWord(word);
        }

        boolean[][] visited = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, visited, root);
            }
        }
        return result;
    }

    private void dfs(char[][] board, int i, int j, boolean[][] visited, TrieNode node) {
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j]) {
            return;
        }
        // check if board item is present in this nodes children
        node = node.children.get(board[i][j]);
        if (node == null) {
            return;
        }
        // now it has been visited
        visited[i][j] = true;
        // add the word to the result
        if (node.word != null) {
            result.add(node.word);
            removeWord(node); // remove node from trie
        }
        // visit neighbours
        dfs(board, i + 1, j, visited, node);
        dfs(board, i - 1, j, visited, node);
        dfs(board, i, j + 1, visited, node);
        dfs(board, i, j - 1, visited, node);
        // this character is valid again
        visited[i][j] = false;
    }

    private void removeWord(TrieNode node) {
        // remove value
        node.word = null;
        // while you can move back up the tree
        while (node.word == null && node.parent != null && node.children.isEmpty()) {
            node.parent.children.remove(node.v); // remove this node from the parents children
            node = node.parent; // move up one node -- back towards root
        }
    }

    private void addWord(String word) {
        TrieNode node = root;
        // 9 ms: for (int i = 0; i < word.length(); i++) {
        // 1 ms: for (int i = word.length() - 1; i >= 0; i--) {
        for (int i = word.length() - 1; i >= 0; i--) {
            char c = word.charAt(i);
            TrieNode next = ((TrieNode) node).getOrCreateChild(c);
            next.parent = node; // move down the tree
            node = next;
        }
        node.word = word; // the last node contains teh whole word
    }
}

// //modifed soln and dscuss post to prune
// //parent.children[c - 'a'] = null; uncommenting this line makes it form 1ms to 7ms
// class Solution {
//     int[] rows = {0, 0, 1, -1};
//     int[] cols = {1, -1, 0, 0};
//     public List<String> findWords(char[][] board, String[] words) {
//         List<String> res = new ArrayList<>();
//         TrieNode root = buildTrie(words);

//         int m = board.length;
//         int n = board[0].length;
//         boolean[][] visited = new boolean[m][n];
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 traverse(board, visited, res, root, i, j, m, n);
//             }
//         }
//         return res;
//     }

//     private void traverse(char[][] board, boolean[][] visited, List<String> res, TrieNode root, int i, int j, int m, int n) {
//         TrieNode parent = root;
//         char c = board[i][j];
//         if (root.children[c - 'a'] == null || root.size == 0) {
//             return;
//         }
//         root = root.children[c - 'a'];
//         if (root.word != null) {
//             res.add(root.word);
//             root.word = null;
//         }
//         visited[i][j] = true;

//         for (int k = 0; k < 4; k++) {
//             int nr = i + rows[k];
//             int nc = j + cols[k];
//             if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
//                 traverse(board, visited, res, root, nr, nc, m , n);
//             }
//         }
//         visited[i][j] = false;
//         if (root.size == 0) {
//             parent.size--;
//             parent.children[c - 'a'] = null;
//         }

//     }


//     private TrieNode buildTrie(String[] words) {
//         TrieNode root = new TrieNode();
//         int i  = 0;
//         for (String word : words) {
//             TrieNode node = root;
//             for (char c : word.toCharArray()) {
//                 i = c - 'a';
//                 if (node.children[i] == null) {
//                     node.children[i] = new TrieNode();
//                     node.size++;
//                 }
//                 node = node.children[i];
//             }
//             node.word = word;
//         }
//         return root;
//     }


// }



// class TrieNode {
//     TrieNode[] children;
//     String word;
//     int size;

//     public TrieNode() {
//         children = new TrieNode[26];
//         size = 0;
//     }
// }