class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> registry; 
    //pairs will have descending order, do to pushing back each time we do "set" 
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        registry[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        //perform binary search to look for key value through the vector of pairs
        if (registry[key].size() == 0) return "";

        int left = 0; 
        int right = registry[key].size() - 1;
        int pos = -1;
        while(left <= right) { 
            int mid = left + (right - left) / 2;

            int currTime = registry[key][mid].first;
            if (currTime <= timestamp) {
                pos = mid;
                left = mid + 1;
            } else { //currTime > timestamp
                right = mid - 1;
            }
        }

        return pos != -1 ? registry[key][pos].second : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);


 {
    love : {10, high}, {20, low}
 }
 */