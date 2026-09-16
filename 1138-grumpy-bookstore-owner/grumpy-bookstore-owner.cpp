class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int left = 0;
        int currSum = 0;
        int maxSum = 0;
        //do currSum as the sum of all existant elements in which the man is not grumpy
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                currSum += customers[i];
            }
        }

        for (int right = 0; right < n; right++) {
            int windowLen = right - left + 1;

            //check window len in case we have to move left
            if (windowLen > minutes) {
                if (grumpy[left] == 1) {
                    currSum -= customers[left];
                }
                left++;
            }

            if (grumpy[right] == 1) {
                currSum += customers[right];
            }

            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};