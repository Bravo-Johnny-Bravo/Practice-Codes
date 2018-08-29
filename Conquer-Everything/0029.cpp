class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == INT_MIN) {
            return (dividend == INT_MIN) ? 1 : 0;
        }
        if (dividend == INT_MIN && divisor == -1) {
            //overflow
            return INT_MAX;
        }
        
        int result = 0;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        
        divisor = abs(divisor);
        if (dividend == INT_MIN) {
            dividend += divisor;
            result++;
        }
        dividend = abs(dividend);
        
        while (divisor <= dividend) {
            int temp = divisor;
            int multiple = 1;
            
            while (dividend - temp >= temp) {
                temp <<= 1;
                multiple <<= 1;
            }
            
            dividend -= temp;
            result += multiple;
        }
        
        return (sign == -1) ? -result : result;
    }
};
