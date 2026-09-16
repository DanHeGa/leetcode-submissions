class Compare {
    public:
        bool operator()(pair<string, int> const p1, pair<string, int> const p2){
            //in a pq, C++ interprets that, if compare is true, p1 has less priority than p2, placing p2 before p1.
            if (p1.second != p2.second) {
                return p1.second > p2.second;
            } 

            return p1.first < p2.first;
        }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        //count word frequencies
        unordered_map<string, int> freqs; //O(m) m for number of words (space)
        for (string word : words) { //O(n) time
            freqs[word]++;
        }

        //custom comparator for maxHeap
        priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq; //space O(m)
        for (auto [word, freq] : freqs) { //O(m) time
            pq.push({word, freq});
            if (pq.size() > k) {
                pq.pop(); //remove less frequent elements
            }
        }

        vector<string> res(k); //O(k) space
        for (int i = k - 1; i >= 0; i--) { //O(k) time
            pair<string, int> currEle = pq.top();
            pq.pop();
            res[i] = currEle.first;
        }

        return res;
    }
};