class Solution {
public:
    bool isPalindrome(int x) {
        long long int sum=0;
        int og=x;
        while(x>0){
            int digit= x%10;
            sum=(sum*10) + digit;
            x=x/10;
        }
        return sum==og;
    }
};