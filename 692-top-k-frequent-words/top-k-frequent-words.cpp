class Compare {
    public:
        bool operator()(pair<string, int> const p1, pair<string, int> const p2){
            if (p1.second < p2.second){
                return true;
            } else if (p1.second == p2.second) {
                return p1.first > p2.first;
            } 

            return false;
        }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        //count word frequencies
        unordered_map<string, int> freqs;
        for (string word : words) {
            freqs[word]++;
        }

        //custom comparator for maxHeap
        priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;
        for (auto [word, freq] : freqs) {
            pq.push({word, freq});
        }

        vector<string> res;
        for (int i = 0; i < k; i++) {
            pair<string, int> currEle = pq.top();
            pq.pop();
            res.push_back(currEle.first);
        }

        return res;
    }
};