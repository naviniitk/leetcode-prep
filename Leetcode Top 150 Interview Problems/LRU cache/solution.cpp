struct Node{
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(): key(0), value(0), next(NULL), prev(NULL){}
    Node(int key, int value): key(key), value(value), next(NULL), prev(NULL)
    {}
};
class LRUCache {
    Node* head=new Node();
    Node* tail=new Node();
    int capacity;
    unordered_map<int, Node*> map;
public:
    LRUCache(int capacity): capacity(capacity) {
        head->next=tail;
        tail->prev=head;
    }
    void add(Node* curr){
        curr->next=head->next;
        head->next->prev=curr;
        head->next=curr;
        curr->prev=head;
        map[curr->key]=curr;
    }

    void erase(Node* ptr){
        map.erase(ptr->key);
        ptr->next->prev=ptr->prev;
        ptr->prev->next=ptr->next;
    }
    
    int get(int key) {
        if (map.count(key)==0) return -1;
        Node* curr=map[key];
        erase(curr);
        add(curr);
        return curr->value;
        
    }
    
    void put(int key, int value) {
        if (map.count(key)>0) erase(map[key]);
        if (map.size()==capacity) erase(tail->prev);
        add(new Node(key, value));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
