class Solution {
public:
    bool isPalindrome(int num) {
        if (num < 0 || (num && num % 10 == 0)) {
            return false;
        }
        int firstHalf = num;
        int secondHalf = 0;
        while (secondHalf < firstHalf) {
            secondHalf = secondHalf * 10 + (firstHalf % 10);
            firstHalf /= 10;
        }   
        return (firstHalf == secondHalf) || (firstHalf == secondHalf / 10);
    }
};
