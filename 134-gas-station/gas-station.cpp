class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int candidate = 0;
        int gain = 0;
        int prefixSumGain = 0; 
        for (int i = 0; i < n; i++) {
            prefixSumGain += gas[i] - cost[i];
            gain += gas[i] - cost[i];

            if (gain < 0) {
                candidate = i + 1;
                gain = 0;
            }
        }

        return prefixSumGain >= 0 ? candidate : -1; 
    }
};

//at the end, even if we have a candidate, we can only return it if prefix sum of the hole array tells us there is an ACTUAL valid way to pass the hole array with ALL the gain peaks and valleys there are

/*
   i = 0 1 2 3 4
gas = [1,2,3,4,5]
cost= [3,4,5,1,2]
*/