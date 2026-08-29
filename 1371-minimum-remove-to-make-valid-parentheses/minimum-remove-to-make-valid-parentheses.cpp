class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> stk;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || !stk.empty() && (s[i] == ')' && stk.top().first == ')')) {
                stk.push({s[i], i});
            } else if (!stk.empty() && s[i] == ')' && stk.top().first == '(') {
                stk.pop();
            } else if (stk.empty() && s[i] == ')') {
                stk.push({s[i], i});
            }
        }

        unordered_set<int> invalids;
        while(!stk.empty()) {
            pair<char, int> ele = stk.top();
            invalids.insert(ele.second);
            stk.pop();
        }

        string res;
        for (int i = 0; i < s.length(); i++) {
            if (!invalids.contains(i)) {
                res += s[i];
            }
        }

        return res;
    }
};