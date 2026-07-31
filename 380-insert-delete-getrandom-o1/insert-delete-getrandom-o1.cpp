class RandomizedSet {
public:
    vector<int> vecSet;
    unordered_map<int, int> idxMap;

    RandomizedSet() {
        vector<int> vecSet = {};
        unordered_map<int, int> idxMap = {};
    }
    
    bool insert(int val) {
        if (idxMap.contains(val)) {
            return false; //we cannot insert an already existing value
        }

        vecSet.push_back(val);
        idxMap[val] = vecSet.size() - 1;      
        return true;
    }
    
    bool remove(int val) {
        if (idxMap.contains(val)) {
            //switch val to remove with last one from the vecSet
            int removeIdx = idxMap[val];
            int lastIdx = vecSet.size() - 1;

            int removeVal = vecSet[removeIdx];
            int lastVal = vecSet[lastIdx];
            vecSet[removeIdx] = lastVal;
            vecSet[lastIdx] = removeVal;
            
            //update the map
            idxMap[lastVal] = removeIdx;

            //remove element from vector and map
            vecSet.pop_back();
            idxMap.erase(val);

            return true;
        }

        return false; //non existent element
    }
    
    int getRandom() {
        int randomIdx = rand() % vecSet.size();
        return vecSet[randomIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */