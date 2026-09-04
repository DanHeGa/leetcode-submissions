class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int n = prices.size();
        int maxProfit = 0;
        while(right < n) {
            if (prices[right] > prices[left]) {
                int profit = prices[right] - prices[left];
                maxProfit = max(maxProfit, maxProfit + profit);
            }

            left++;
            right++;
        }

        return maxProfit;
    }
};

/*
prices = [7,1,5,3,6,4]

totalprofit = 15
maxProfit = 4

i = 0 1  2 3 4 5
p = [7,1,5,3,6,4]

*/