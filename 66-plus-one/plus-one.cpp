class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());

        int carry = 0;
        for (int i = 0; i < digits.size(); i++) {
            if (i == 0) {
                int ele = digits[i];
                digits[i] = (digits[i] + 1) % 10;
                carry = (ele + 1) / 10;
                continue;
            }

            int op = digits[i] + carry;
            digits[i] = op % 10;
            carry = op / 10;
        }

        if (carry > 0){
            digits.push_back(carry);
        }

        reverse(digits.begin(), digits.end());
        return digits;
    }
};