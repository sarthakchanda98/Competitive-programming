/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) 
    {
        if(head == null)
        return null;

        Node curr = head;
        while(curr!=null)
        {
            Node newnode = new Node(curr.val);
            newnode.next = curr.next;
            curr.next = newnode;
            curr = curr.next.next;
        }
        curr = head;
        while(curr!=null)
        {
            if(curr.random!=null)
           {
                curr.next.random = curr.random.next;
           }
           curr=curr.next.next;
        }
        curr = head;
        Node clonedhead = head.next;
        while(curr!=null)
        {
            Node clonednode = curr.next;
            curr.next = clonednode.next;
            if(clonednode.next!=null)
            {
                clonednode.next = clonednode.next.next;
            }
            curr = curr.next;
        }
        return clonedhead;
    }
}