class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = accumulate(nums.begin(),nums.end(),0); // 11
        int target = total-x; // 6
        if(target<0){
            return -1;
        }
        if(target == 0){
            return nums.size();

        }

        int sum = 0;
        int left = 0;
        int maxlen = -1;

        for(int right =0 ;right<nums.size();right++){
            sum = sum + nums[right];

            while(sum>target){
                sum = sum-nums[left];
                left++;
            }
            if(sum == target){
                maxlen = max(maxlen , right-left+1);
            }
        }
        if(maxlen == -1){
            return -1;
        }
        return nums.size()-maxlen;
    }
};