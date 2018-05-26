class Solution {
public:
    int isMatchHelper(string &input, string &pattern, int inpIndex, int patIndex, vector<vector<int> > &dp) {
        if (dp[inpIndex][patIndex] != -1) {
            return dp[inpIndex][patIndex];
        }
        if (patIndex == pattern.size()) {
            return inpIndex == input.size();
        }
        int match = 0;
        bool firstMatch = inpIndex < input.size() && (input[inpIndex] == pattern[patIndex] || pattern[patIndex] == '.');
        if (patIndex + 1 < pattern.size() && pattern[patIndex + 1] == '*') {
            match = match || isMatchHelper(input, pattern, inpIndex, patIndex + 2, dp);
            if (firstMatch) {
                match = match || isMatchHelper(input, pattern, inpIndex + 1, patIndex, dp);
            }
        } else if (firstMatch) {
            match = isMatchHelper(input, pattern, inpIndex + 1, patIndex + 1, dp);
        }
        return dp[inpIndex][patIndex] = match;
    }
    
    bool isMatch(string input, string pattern) {
        vector<vector<int> > dp(input.size() + 1, vector<int> (pattern.size() + 1, -1));
        return (bool) isMatchHelper(input, pattern, 0, 0, dp);
    }
};
