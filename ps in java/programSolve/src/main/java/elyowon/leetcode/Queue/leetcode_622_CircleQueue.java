package elyowon.leetcode.Queue;



public class leetcode_622_CircleQueue {


    private int capacity;
    private int size;
    private int head;
    private int tail;
    private int[] elements;

    public leetcode_622_CircleQueue(int capacity) {
        this.capacity = capacity;
        this.size = 0;
        this.head = 0;
        this.tail = 0;
        this.elements = new int[capacity];
    }


    public boolean enQueue(int data) {
        if(isFull()){
            return false;
        }
        elements[tail] = data;
        tail = (tail +1) % capacity;
        size++;
        return true;
    }

    public boolean deQueue(){
        if(isEmpty()){
            return false;
        }

        head = (head + 1) % capacity;
        size--;
        return true;
    }


    public int front(){
        if(isEmpty()){
            return -1;
        }
        return elements[head % capacity];
    }

    public int rear(){
        if(isEmpty()){
            return -1;
        }
        return elements[(tail + capacity -1 ) % capacity];
    }
    public boolean isEmpty(){
        return size == 0;
    }

    public int getSize(){
        return size;
    }

    public boolean isFull(){
        return size == capacity;
    }

}
