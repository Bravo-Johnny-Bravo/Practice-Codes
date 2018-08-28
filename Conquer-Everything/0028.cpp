class Solution {
    vector<int> computeLPS(string& pattern) {
        vector<int> lps(pattern.size());
        int len = 0;
        lps[0] = 0;
        int i = 1;
        while (i < pattern.size()) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len) {
                    len = lps[len - 1]; 
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    
    int KMPSearch(string& pattern, string& text) {
        vector<int> lps = computeLPS(pattern);
        int i = 0;
        int j = 0;
        while (i < text.size()) {
            if (pattern[j] == text[i]) {
                i++;
                j++;
            }
            if (j == pattern.size()) {
                return (i - j);
            } else if (i < text.size() && pattern[j] != text[i]) {
                if (j) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return -1;
    }
    
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        return KMPSearch(needle, haystack);
    }
};
