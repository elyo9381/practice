package elyowon.divAndCon;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;


// Class for a tree node
class T_Node {
    // Members
    int key;
    T_Node left, right;

    // Constructor
    public T_Node(int key) {
        this.key = key;
        left = right = null;
    }
}

// A class to represent a queue item. The queue is used to do Level
// order traversal. Every Queue item contains node and horizontal
// distance of node from root
class QItem {
    T_Node node;
    int hd;

    public QItem(T_Node n, int h) {
        node = n;
        hd = h;
    }
}

// Class for a Binary Tree
class Tree {
    T_Node root;

    // Constructors
    public Tree() {
        root = null;
    }

    public Tree(T_Node n) {
        root = n;
    }

    // This method prints nodes in top view of binary tree
    public void printTopView() {
        // base case
        if (root == null) {
            return;
        }

        // Creates an empty hashset
        HashSet<Integer> set = new HashSet<>();

        // Create a queue and add root to it
        Queue<QItem> Q = new LinkedList<QItem>();
        Q.add(new QItem(root, 0)); // Horizontal distance of root is 0

        // Standard BFS or level order traversal loop
        while (!Q.isEmpty()) {
            // Remove the front item and get its details
            QItem qi = Q.remove();
            int hd = qi.hd;
            T_Node n = qi.node;

            // If this is the first node at its horizontal distance,
            // then this node is in top view
            if (!set.contains(hd)) {
                set.add(hd);
                System.out.print(n.key + " ");
            }

            // Enqueue left and right children of current node
            if (n.left != null) Q.add(new QItem(n.left, hd - 1));
            if (n.right != null) Q.add(new QItem(n.right, hd + 1));
        }
    }
}

// Driver class to test above methods
public class PrintTopViewofTree {
    public static void main(String[] args) {
    /* Create following Binary Tree
       1
     /  \
    2    3
     \
      4
       \
        5
         \
          6*/
        T_Node root = new T_Node(1);
        root.left = new T_Node(2);
        root.right = new T_Node(3);
        root.left.right = new T_Node(4);
        root.left.right.right = new T_Node(5);
        root.left.right.right.right = new T_Node(6);
        Tree t = new Tree(root);
        System.out.println("Following are nodes in top view of Binary Tree");
        t.printTopView();
    }
}