class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freqT;
        unordered_map<char, int> freqS;

        //get T frequency of each char
        for (char c : t) {
            freqT[c]++;
        }

        int minLen = INT_MAX;
        int minLeft, minRight;

        int have = 0;
        int need = freqT.size();
        
        int left = 0;
        for (int r = 0; r < s.length(); r++) {
            // add to s[r] frequency count
            char currChar = s[r];
            freqS[currChar]++;

            //if freq of a char is equal in both maps, then add to have
            if (freqT.contains(currChar) && freqT[currChar] == freqS[currChar]) {
                have++;
            }

            while (have == need) {
                //update minlen
                int currLen = r - left + 1;
                if (currLen < minLen) {
                    minLen = currLen;
                    minLeft = left;
                    minRight = r;
                } 

                //move left until we dont have need == ave anymore (so we can see more options from different start positions)
                freqS[s[left]]--;
                if (freqT.contains(s[left]) && freqS[s[left]] < freqT[s[left]]) {
                    have--;
                }

                left++;
            }
        }

        return minLen != INT_MAX ? s.substr(minLeft, minLen) : ""; 
    }
};