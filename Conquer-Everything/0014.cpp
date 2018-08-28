class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        if (strs.empty()) {
            return prefix;
        }
        bool done = false;
        for (int i = 0; i < strs[0].length() && !done; i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (i == strs[j].length() || strs[j][i] != strs[0][i]) {
                    done = true;
                    break;
                }
            }
            if (!done) {
                prefix += strs[0][i];
            }
        }
        return prefix;
    }
};
