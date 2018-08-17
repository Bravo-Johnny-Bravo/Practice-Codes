class Solution {
public:
    int reverse(int num) {
        int rev = 0;
        while (num) {
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && num > 7)) {
                return 0;
            }
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && num < -8)) {
                return 0;
            }
            rev = rev * 10 + (num % 10);
            num /= 10;
        }
        return rev;
    }
};
