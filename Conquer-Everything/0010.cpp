class Solution {
    int match(string& input, string& pattern, int i, int j, vector<vector<int> >& dp) {
        if (j == pattern.length()) {
            return i == input.length();
        }   
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        bool firstMatch = (i < input.length() && (input[i] == pattern[j] || pattern[j] == '.'));
        
        if (j + 1 < pattern.length() && pattern[j + 1] == '*') {
            return dp[i][j] = match(input, pattern, i, j + 2, dp) 
                            || (firstMatch && match(input, pattern, i + 1, j, dp));
        }
        return dp[i][j] = firstMatch && match(input, pattern, i + 1, j + 1, dp);
    }
    
public:
    bool isMatch(string input, string pattern) {
        vector<vector<int> > dp(input.length() + 1, vector<int>(pattern.length(), -1));
        return match(input, pattern, 0, 0, dp);
    }
};
