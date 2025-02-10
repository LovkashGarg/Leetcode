class DLL{
    public:
    int key,val;
    DLL *next=nullptr;
    DLL * prev=nullptr;
    DLL(int key,int val){
        this->key=key;
        this->val=val;
    }
};
class LRUCache {
public:
int size;
unordered_map<int,DLL *>m;
 DLL *head=new DLL(-1,-1);
        DLL *tail=new DLL(-1,-1);
    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void insert_after_head(DLL *node){
        // now I can insert it 
        DLL *temp=head->next;
        head->next=node;
        node->prev=head;
        temp->prev=node;
        node->next=temp;
    }
    
    int get(int key) {
         
         if(m.find(key)==m.end()){
            return -1;
         }
         else{
            // i have to delete this node 
            DLL *node=m[key];
            delete_the_node(m[key]);
            insert_after_head(node);
            return node->val;
         }

    }
    
    void delete_the_node(DLL *node){

       DLL * forw=node->next;
       DLL *previous=node->prev;
       previous->next=forw;
       forw->prev=previous;
    //    node->next=nullptr;
    //    node->prev=nullptr;

    }
    void insert_beforetail(DLL *node){
        
        DLL * temp=tail->prev;
        tail->prev=node;
        node->next=tail;
        node->prev=temp;
        temp->next=node;

    }

    void put(int key, int value) {
        
        // to check if already present 
        if(m.find(key)!=m.end()){
            // delete this node 
            DLL *node = m[key];
            delete_the_node(node);
            node->val=value;
            insert_after_head(node);
            return;
        }
        else if(m.size() >=size){
           // here I need to  delete the node before tail 
           DLL *node=tail->prev;
           m.erase(node->key);
           delete_the_node(node);
           delete node;
        }
            // not present create a new node 
            DLL *temp=new DLL(key,value);
            m[key]=temp;
            // I need to insert before the tail
            insert_after_head(temp);
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */