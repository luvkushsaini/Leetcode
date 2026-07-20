
class LRUCache {
    class node{
        int key;
        int val;
        node prev;
        node next;

        node(int key,int val){
            this.key=key;
            this.val=val;
        }
    }

    private int capacity;
    private Map<Integer,node>mp;
    private node head;
    private node tail;

    public LRUCache(int capacity) {
        this.capacity=capacity;
        mp=new HashMap<>();
        head=new node(-1,-1);
        tail=new node(-1,-1);
        head.next=tail;
        tail.prev=head;
    }

    private void remove(node nd){
        node pr=nd.prev;
        node nx=nd.next;

        pr.next=nx;
        nx.prev=pr;
    }

    private void insert(node nd){
        node last=tail.prev;
        last.next=nd;
        nd.prev=last;
        nd.next=tail;   
        tail.prev=nd;
    }
    
    public int get(int key) {
        if(!mp.containsKey(key))return -1;
        node nd=mp.get(key);
        remove(nd);
        insert(nd);
        return mp.get(key).val;
    }
    
    public void put(int key, int value) {

    if (mp.containsKey(key)) {

        node nd = mp.get(key);
        nd.val = value;

        remove(nd);
        insert(nd);

        return;
    }

    if (mp.size() == capacity) {

        node lru = head.next;

        remove(lru);
        mp.remove(lru.key);
    }

    node nd = new node(key, value);

    insert(nd);
    mp.put(key, nd);
}
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */