class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestProfit = 0;
        int minLeft = 0;
        int left = 0;
        int right = 0;

        while(right < prices.size()) {
            int currProfit = prices[right] - prices[minLeft];
            right++;
            if (currProfit > bestProfit) {
                bestProfit = currProfit;
            } else {
                if (prices[left] < prices[minLeft]) {
                    minLeft = left;
                }
            }
            left++;
        }

        return bestProfit;
    }
};

/*
 maxProfit = 4
 currProfit = 4

 minLeft = l; //check we have the lowest left value
 
 [7,1,5,3,6,4] 
  l
  r



*/