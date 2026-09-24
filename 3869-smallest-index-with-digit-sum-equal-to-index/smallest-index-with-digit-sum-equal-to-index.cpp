class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0 ; i<nums.size(); i++){
            int digit = nums[i];
            int sum =0;
            while(digit>0){
                int single = digit%10;
                sum = sum+single;
                digit = digit /10;
            }
            if(i == sum){
                return i;
            }
        }
        return -1;
        
    }
};