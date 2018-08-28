class Solution {
    void makeParanthesis(int remaining, int balance, string& cur, vector<string>& paranthesis) {
        if (remaining == 0) {
            if (balance == 0) {
                paranthesis.push_back(cur);
            }
            return;
        }   
        if (balance < 0 || balance > remaining) {
            return;
        }
        cur += '(';
        makeParanthesis(remaining - 1, balance + 1, cur, paranthesis);
        cur.pop_back();
        cur += ')';
        makeParanthesis(remaining - 1, balance - 1, cur, paranthesis);
        cur.pop_back();
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> paranthesis;
        string cur;
        makeParanthesis(2 * n, 0, cur, paranthesis);
        return paranthesis;
    }
};
