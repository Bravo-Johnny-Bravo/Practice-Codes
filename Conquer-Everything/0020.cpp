class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                brackets.push(ch);
            } else {
                if (brackets.empty()) {
                    return false;
                }
                switch(brackets.top()) {
                    case '(' :  
                        if (ch != ')') return false;
                        break;
                    case '[' :
                        if (ch != ']') return false;
                        break;
                    case '{' :
                        if (ch != '}') return false;
                        break;
                }
                brackets.pop();
            }
        }
        return brackets.empty();
    }
};
