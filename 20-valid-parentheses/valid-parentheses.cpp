class Solution {
public:
    unordered_map<char, char> pairs = {
        { ')' , '('},
        { ']' , '['},
        { '}' , '{'}
    };
    bool isValid(string s) {
        stack<char> stk;

        for (char letter : s ) {
            if (pairs.count(letter)){
                if (!stk.empty() && stk.top() == pairs[letter]) {
                    stk.pop();
                } else {
                    return false;
                }
            } else {
                stk.push(letter);
            }
        }

        return stk.empty();

    }
};