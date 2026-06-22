class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freqT;
        unordered_map<char, int> freqS;

        for (char letter : t) {
            freqT[letter]++;
        }

        int minLen = INT_MAX;
        int minLeft, minRight;
        int have = 0; 
        int need = freqT.size();

        int n = s.length();
        int r = 0, l = 0;
        while (r < n) {
            freqS[s[r]]++;

            if (freqT.find(s[r]) != freqT.end() &&
                freqS[s[r]] == freqT[s[r]]) {
                    have++;
            }

            while (have == need) {
                int len = r - l + 1;
                if (len < minLen) {
                    minLen = len;
                    minLeft = l;
                    minRight = r;
                }

                freqS[s[l]]--;
                if (freqT.count(s[l]) && freqS[s[l]] < freqT[s[l]]){
                    have--;
                }

                l++;
            }

            r++;
        }

        //int minLeft, minRight;
        string minSubStr = minLen != INT_MAX ? s.substr(minLeft, minLen) : "";
        cout << "Res: " << minSubStr << endl;
        return minSubStr;
    }
};

/*
freqT = {
    A : 1,
    B : 1,
    C : 1
}

freqS ={

}

*/