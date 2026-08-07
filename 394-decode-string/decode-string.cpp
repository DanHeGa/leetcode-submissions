class Solution {
public:
    string decodeString(string s) {
        stack<int> numStk;
        stack<string> subStrStk;

        string currStr = "";
        int currNum = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                currNum = currNum * 10 + (s[i] - '0');
            } else if (s[i] == '[') {
                numStk.push(currNum);
                currNum = 0;
                subStrStk.push(currStr);
                currStr = "";
            } else if  (s[i] == ']') {
                int currNum = numStk.top();
                numStk.pop();
                string prevStr = subStrStk.top();
                subStrStk.pop();

                string inner = "";
                for (int i = currNum; i > 0; i--) {
                    inner += currStr;
                }

                currStr = prevStr + inner;

            } else { //it's a letter/char
                currStr += s[i];
            }
        }

        return currStr;
    }
};