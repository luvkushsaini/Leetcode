class Node{
    int key;
    int value;

    Node next;
    Node prev;

    Node(int key,int value){
        this.key=key;
        this.value=value;
        next=null;
        prev=null;
    }
}

class LRUCache {
     int capacity;
     Map<Integer,Node>mp=new HashMap<>();
     Node head;
     Node tail;



    public LRUCache(int capacity) {
        this.capacity=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head.next=tail;
        tail.prev=head;
        mp.clear();
    }
    
    public int get(int key) {
        if(!mp.containsKey(key))return -1;


         
        Node curr=mp.get(key);
        Node currNext=curr.next;
        curr.prev.next=currNext;
        currNext.prev=curr.prev;

        Node headNext=head.next;
        head.next=curr;
        headNext.prev=curr;
        curr.next=headNext;
        curr.prev=head;

        return curr.value;

        
    }
    
    public void put(int key, int value) {
        if(mp.containsKey(key)){
            Node curr=mp.get(key);
            curr.value=value;
            Node currNext=curr.next;
            curr.prev.next=currNext;
            currNext.prev=curr.prev;

            Node headNext=head.next;
            head.next=curr;
            curr.next=headNext;
            curr.prev=head;
            headNext.prev=curr;
            return ;
        }

        if(mp.size()==capacity){
            Node node=tail.prev;
            mp.remove(node.key);
            node.prev.next=tail;
            tail.prev=node.prev;
        }
        Node newNode= new Node(key,value);
        mp.put(key,newNode);
        Node headNext=head.next;
        head.next=newNode;
        newNode.next=headNext;
        newNode.prev=head;
        headNext.prev=newNode;

    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */