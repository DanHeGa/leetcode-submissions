class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int, vector<char>> digitMap = {
            {2, {'a', 'b', 'c'}},
            {3, {'d', 'e', 'f'}},
            {4, {'g', 'h', 'i'}},
            {5, {'j', 'k', 'l'}},
            {6, {'m', 'n', 'o'}},
            {7, {'p', 'q', 'r', 's'}},
            {8, {'t', 'u', 'v'}},
            {9, {'w', 'x', 'y', 'z'}},
        };

        vector<string> res = {""};
        for (char digit : digits) {
            vector<string> subRes;
            vector<char> currDigitMap = digitMap[digit - '0'];
            for (int i = 0; i < res.size(); i++) {
                for (int j = 0; j < currDigitMap.size(); j++) {
                    string comb = res[i] + currDigitMap[j];
                    subRes.push_back(comb);
                }
            }

            res = subRes;
        }

        return res;
    }
};

/*
digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

mp = {
    2 : [a,b,c],
    3 : [d,e,f]
}
for each char of digits

    iter over '2' options:
    result = [a, b, c]

   iter over '3' options:
    subRest = []
    for each curr res option, 
        we iterate the whole '3' options
        append curr res char + option, and add to subRes
        subResult = [ad, ae, af, bd, be, bf, cd, ce, cf]

    finally, set result to now be subresult
    result = []
*/