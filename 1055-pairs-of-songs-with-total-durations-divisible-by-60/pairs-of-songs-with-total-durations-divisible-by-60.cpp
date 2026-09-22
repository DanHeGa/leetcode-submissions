class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        vector<int> freqs(61, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += freqs[(60 - (time[i] % 60)) % 60]; //add what we need to come with a div by 60 number/s
            freqs[time[i] % 60]++; //add frequency to that remainder
        }

        return ans;
    }
};


/*
time = [30,20,150,100,40]
all pairs divisible by 60 && where i < j 

for each song, look for it's remainder of 60 - (song[i] % 60)
like in two sum
*/