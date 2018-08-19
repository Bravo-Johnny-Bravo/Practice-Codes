class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        //ignore whitespaces
        while (i < str.length() && str[i] == ' ') {
            i++;
        }
        //get sign
        int sign = 1;
        if (i < str.length()) {
            if (str[i] == '-') {
                sign = -1;
                i++;
            } else if (str[i] == '+') {
                i++;
            }
        }
        //construct number
        int num = 0;
        while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
            //check for overflow
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && (str[i] - '0' > INT_MAX - num * 10))) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            num = num * 10 + (str[i] - '0');
            i++;
        }
        return sign * num;
    }
};
