class Solution {
public:
    int reverseDegree(string s) {
        int sum =0 ;
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            int alphabet = ch - 'a' + 1;
            int rev = 27-alphabet;
            int product = (i+1) * rev;
            sum = sum +  product;
        }
        return sum;
    }
};