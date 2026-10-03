class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int j = 0;
        int k = 0; //writer
        int n = chars.size();
        while(i < n) {
            j = i + 1;
            while(j < n && chars[j] == chars[i]) {
                j++;
            }

            chars[k] = chars[i];
            k++;

            int currLen = j - i;
            if (currLen > 1) {
                string currLenStr = to_string(currLen);
                for (char c : currLenStr) {
                    chars[k] = c;
                    k++;
                }
            }

            //move to next group
            i = j;
        }

        return k;
    }
};

/*
    i =   0   1   2   3   4   5   6  
chars = ["a","a","b","b","c","c","c"]
          l
          r

currCounter = 0
s = "a2b2c3"

return s.length()

when l and r not equal, append currCounter to s, and restart it, as well as adding this new char to s

at the end, append currCount to s

*/