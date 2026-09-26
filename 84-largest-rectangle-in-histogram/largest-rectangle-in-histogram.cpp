class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int n = heights.size();
        vector<int> right(n, n);
        vector<int> left(n, -1);

        for (int i = 0; i < n; i++) {
            int currEle = heights[i];
            while(!stk.empty() && currEle <= heights[stk.top()]) {
                int stkIdx = stk.top();
                stk.pop();
                right[stkIdx] = i;
            }

            if (!stk.empty()) {
                left[i] = stk.top();
            }

            stk.push(i);
        }


        //get max area
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int leftIdx = left[i];
            int rightIdx = right[i];

            int area = heights[i] * (rightIdx - leftIdx - 1);
            maxArea = max(maxArea, area); 
        }

        return maxArea;
    }
};


/*
heights = [2,1,5,6,2,3]  output = 10

use stack, in ascending order
- if currEle (while) is < stk.top, 
    update right with currEle

- if stack not empty AND currEle > stk.top
    update left of currEle

at the end, get the area with each right and left measure to get maxArea
*/