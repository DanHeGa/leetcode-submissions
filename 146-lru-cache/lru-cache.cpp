struct DllNode {
    int key;
    int val;
    DllNode* next;
    DllNode* prev;

    DllNode(int key, int val) : key(0), val(0), next(nullptr), prev(nullptr){}
    DllNode(int key, int val, DllNode* prev, DllNode* next) {
        this->key = key;
        this->val = val;
        this->prev = prev;
        this->next = next;
    } 
};

class LRUCache {
    unordered_map<int, DllNode*> mp;
    int capacity;
    int currSize;
    DllNode* dh = new DllNode(0, 0, nullptr, nullptr);
    DllNode* dt = new DllNode(0, 0, nullptr, nullptr);
public:
    LRUCache(int capacity) {
        //direct dh to dt and the other way around too
        dh->next = dt;
        dt->prev = dh;
        this->capacity = capacity;
        currSize = 0;
        mp = {};
    }

    void removeNode(DllNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToFront(DllNode* node) {
        node->next = dh->next;
        dh->next->prev = node;
        dh->next = node;
        node->prev = dh;
    }

    int get(int key) {
        if (mp.contains(key)) {
            DllNode* used = mp[key];
            removeNode(used);
            moveToFront(used);
            return used->val;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (mp.contains(key)) {
            //we change the value, and manage it as used (remove, and re attach as first)
            mp[key]->val = value;
            removeNode(mp[key]);
            moveToFront(mp[key]);
        } else {
            //else, we create it, attach it in the front, and if more than capacity, remove the last element in DLL
            //add to map
            mp[key] = new DllNode(key, value, nullptr, nullptr);
            //add to dll (move to front)
            moveToFront(mp[key]);
            currSize++;
            
            if (currSize > capacity) {
                //remove last node in dll (dt->prev)
                DllNode* toDelete = dt->prev;
                removeNode(toDelete);
                mp.erase(toDelete->key);
                delete toDelete;
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