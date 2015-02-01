class StackEmptyException extends Exception {
        
}
public class StackOfStrings1<Item> {
    private class Node {
        Item val;
        Node next;
    }

    private Node head = null;
    public void push(Item val) {
        Node oldhead = head;
        Node newNode = new Node();
        newNode.val = val;
        newNode.next = oldhead;
        head =  newNode;
    }
    public Item pop() {
        Node oldhead = head;
        head = head.next;
        return oldhead.val;
    }
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        StackOfStrings1<String> s = new StackOfStrings1<String>();
        s.push("a");s.push("b");
        System.out.println(s.pop());
        StdOut.println(s.pop());
        StackOfStrings1<Integer> s1 = new StackOfStrings1<Integer>();
        s1.push(1);s1.push(2);
    }
    
}
