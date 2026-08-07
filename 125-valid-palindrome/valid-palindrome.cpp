class Solution {
public:
    bool isPalindrome(string s) {
        string inner = "";
        for (char c : s) {
            if (isalnum(static_cast<unsigned char>(c))) {
                inner += tolower(c);
            }
        }   

        int left = 0; 
        int right = inner.length() - 1;
        while(left <= right) {
            if (inner[left] != inner[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

/*
Get a lower case with number string (with no non-alphanumeric chars)
iterate over the build string with pointers (left and right) to see if we actuall have a palindrome
if we see any diff char when moving pointers, then return false (no palindrome)
*/