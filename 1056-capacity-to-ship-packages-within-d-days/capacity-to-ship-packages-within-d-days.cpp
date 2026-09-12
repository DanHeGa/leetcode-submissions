class Solution {
public:

    int isFeasible(vector<int>& weights, int capacity) {
        int requiredDays = 1;
        int currSum = 0;
        for (int i = 0; i < weights.size(); i++) {
            currSum += weights[i];
            if (currSum > capacity) {
                requiredDays++;
                currSum = weights[i];
            }
        }

        return requiredDays;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        //get the search space, min capacity and max capacity
        int minCapacity = 0;
        int maxCapacity = 0; //maybe add +1 to make it inclusive
        for (int weight : weights) {
            minCapacity = max(minCapacity, weight);
            maxCapacity += weight;
        }

        int left = minCapacity;
        int right = maxCapacity;
        while(left < right) {
            int mid = left + (right - left) / 2;

            //check if mid capacity is viable
            int requiredDays = isFeasible(weights, mid);
            //if we can make the shipments in > than days, we need more capacity
            if (requiredDays > days) {
                left = mid + 1;
            } else { //requiredDays <= days :: viable/feasible
                //if we can make the shipments in < than days, we can keep moving to the left
                right = mid;
            }
        }

        return left;
    }
};