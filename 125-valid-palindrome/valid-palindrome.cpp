class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0; 
        int right = s.length() - 1;
        while(left <= right) {
            if (!isalnum(static_cast<unsigned char>(s[left]))) {
                left++;
            } else if(!isalnum(static_cast<unsigned char>(s[right]))) {
                right--;
            } else {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }

                left++;
                right--;
            }
        }

        return true;
    }
};

/*
Get a lower case with number string (with no non-alphanumeric chars)
iterate over the build string with pointers (left and right) to see if we actuall have a palindrome
if we see any diff char when moving pointers, then return false (no palindrome)
*/