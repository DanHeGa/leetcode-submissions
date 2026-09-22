class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();

        //get freq map of second half
        unordered_map<int, int> freqs;
        for (int i = 0; i < n; i++) {
            freqs[arr[i]]++;
        }

        //take all unique numbers
        vector<int> uniques;
        for (auto [number, frequency] : freqs) {
            uniques.push_back(number);
        }

        //sort by absolute value
        sort(uniques.begin(), uniques.end(), [](int &a, int &b) {
            return abs(a) < abs(b);
        });

        //each time we see the freq, we decrease it
        for (int i = 0; i < uniques.size(); i++) {
            if (freqs[uniques[i] * 2] < freqs[uniques[i]]) {
                return false;
            }

            freqs[uniques[i] * 2] -= freqs[uniques[i]];
        }

        return true;
    }
};

/*     0  1 2  3 
arr = [4,-2,2,-4]
vis = [0, 0,0,0] //visited

iterate over first half
make a hashmap of the second half

if doubled is in map
reduce freq in map
else return false //everyone should have their doubled version
*/