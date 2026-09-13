class Solution {
public:
    bool isPalindrome(int x) {
        int num = x;
        long rev = 0;
        while(x > 0){
            int lastdigit = x%10;
            rev = (rev*10) + lastdigit;
            x /= 10;
        }
        return (rev==num);
    }
};