class Solution {
    void expandAroundCenter(string &s, int start, int end, pair<int, int> &longest) {
        while (start >= 0 && end < s.length() && s[start] == s[end]) {
            int longestSize = longest.second - longest.first + 1;
            int currentSize = end - start + 1;
            if (currentSize > longestSize) {
                longest = {start, end};
            }
            start--;
            end++;
        }
    }
    
public:
    string longestPalindrome(string s) {
        pair<int, int> longest = {0, -1};
        for (int i = 0; i < s.length(); i++) {
            expandAroundCenter(s, i, i, longest);
            expandAroundCenter(s, i, i + 1, longest);
        }
        int startIndex = longest.first;
        int size = longest.second - longest.first + 1;
        return s.substr(startIndex, size);
    }
};
