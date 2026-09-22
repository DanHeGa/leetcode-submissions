class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> freqs;
        for (string word : words) {
            freqs[word]++;
        }

        int res = 0;
        int symetricRemainders = 0;
        for (auto [word, freq] : freqs) {
            string reversed = word;
            reverse(reversed.begin(), reversed.end());

            if (word[0] == word[1]) {
                symetricRemainders += freq & 1; //checks if it is odd, and adds one if it is
                res += ((freq / 2) * 2) * 2;
            } else if (freqs.contains(reversed)){ //we know is an asymetric string, so we only need to check if its reverse its in the freqs map
                res += min(freq, freqs[reversed]) * 2; // *2 for the length
            }
        }

        if (symetricRemainders > 0) {
            res += 2;
        }

        return res;
    }
};


/*
["ab","ty","yt","aa","aa","ab"]
freqs = {
    ab : 2
    ty : 2
    yt : 1
    aa : 2
}

for each freq, check if asymetric or not
    aa
        check odd or even count, 
            add remainder to extra var counter
            add aa(( freq / 2 ) * 2) * 2

            //first 2 to get the actual EVEN string count, second two to represent their palindrome mirror, and third for the length

        else 
    ab
        find reverse version in freqs
            if existant, add to res the min freq of the reversed and the current //to handle when one was more frequent than another

return count
*/