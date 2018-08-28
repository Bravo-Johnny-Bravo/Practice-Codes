class Solution {
    map<char, string> digitToAlphabetsMap;
    
public:
    Solution() {
        char alphabet = 'a';
        for (char digit = '2'; digit <= '9'; digit++) {
            string alphabets;
            int iterations = (digit == '7' || digit == '9') ? 4 : 3;
            for (int i = 0; i < iterations; i++) {
                alphabets += alphabet;
                alphabet++;
            }
            digitToAlphabetsMap[digit] = alphabets;
        }
    }
    
    void makeCombinations(string& digits, int idx, string& cur, vector<string>& combinations) {
        if (idx == digits.length()) {
            combinations.push_back(cur);
            return;
        }    
        for (char alphabet : digitToAlphabetsMap[digits[idx]]) {
            cur.push_back(alphabet);
            makeCombinations(digits, idx + 1, cur, combinations);
            cur.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if (digits.length() == 0) {
            return combinations;
        }
        string cur;
        makeCombinations(digits, 0, cur, combinations);
        return combinations;
    }
};
