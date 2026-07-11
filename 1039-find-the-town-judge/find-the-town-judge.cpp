class Solution {
public:

    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> trustCount(n);
        unordered_set<int> citizens;
        //initialize map values, all in 0
        for (int i = 1; i <= n; i++) {
            trustCount[i] = 0;
        }

        // [[1,3],[2,3]]
        for(auto &ele : trust) {
            int truster = ele[0];
            int trusted = ele[1];
            trustCount[trusted]++;
            citizens.insert(truster);
        }
        
        for(int i = 1; i <= n; i++) {
            if (trustCount[i] == n - 1 && !citizens.count(i)) {
                return i;
            }
        }

        return -1;
    }
};