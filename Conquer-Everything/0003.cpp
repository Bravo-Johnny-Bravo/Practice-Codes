class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charAtIndex;
        int ans = 0;
        for (int i = 0, j = 0; i < s.length(); i++) {
            if (charAtIndex.count(s[i])) {
                j = max(j, charAtIndex[s[i]] + 1);
            }
            charAtIndex[s[i]] = i;
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
