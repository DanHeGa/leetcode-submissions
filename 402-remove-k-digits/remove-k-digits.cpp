class Solution {
public:
    string removeKdigits(string num, int k) {
        string stk;

        for(char& c : num) {
            while(k > 0 && !stk.empty() && c < stk.back()) {
                stk.pop_back();
                k--;
            }

            stk.push_back(c);
        }  

        //if all chars were already in increasing order, pop largest back ones to be left with smaller front ones (1228899 , k = 3) -> 1228
        while(k > 0) {
            stk.pop_back();
            k--;
        }

        //handle zeros
        int i = 0; 
        while(i < stk.size() && stk[i] == '0') {
            i++;
        }

        cout << "stk: " << i << endl;
        string res =  stk.substr(i);
        return res.empty() ? "0" : res;
    }
};