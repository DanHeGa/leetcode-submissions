struct dllNode {
    int val;
    int key;
    dllNode* prev;
    dllNode* next;

    dllNode(int key, int val) {
        this->key = key;
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
    dllNode(int key, int val, dllNode* prev, dllNode* next) {
        this->key = key;
        this->val = val;
        this->prev = prev;
        this->next = next;
    }
};

class LRUCache {
private:
    int capacity; 
    int currSize;
    unordered_map<int, dllNode*> mp;
    dllNode* dh = new dllNode(0, 0); //dummy head
    dllNode* dt = new dllNode(0, 0); //dummy tail

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->currSize = 0; 
        this->mp = {};
        this->dh->next = dt;
        this->dt->prev = dh;
    }
    
    void removeNode(dllNode* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    void moveToFront(dllNode* node) {
        node->next = dh->next;
        node->prev = dh;
        dh->next->prev = node;
        dh->next = node;
    }

    int get(int key) {
        if (!mp.contains(key)) {
            return -1;
        } else {
            dllNode* currNode = mp[key];
            removeNode(currNode);
            moveToFront(currNode);
            return currNode->val;
        }
    }
    
    void put(int key, int value) {
        //if key in map, only update it's value, move it to front
        if (mp.contains(key)) {
            dllNode* node = mp[key];
            node->val = value; //update its value
            removeNode(node);
            moveToFront(node);
        } else {
            dllNode* newNode = new dllNode(key, value, dh, dh->next);
            dh->next->prev = newNode;
            dh->next = newNode;
            mp[key] = newNode;
            currSize++;
            if (currSize > capacity){
                dllNode* nodeToDelete = dt->prev;
                removeNode(nodeToDelete);
                mp.erase(nodeToDelete->key);
                delete(nodeToDelete);
                currSize--;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */