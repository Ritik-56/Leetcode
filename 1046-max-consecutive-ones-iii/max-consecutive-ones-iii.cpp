class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int ans=0;
        for(int j=i;j<nums.size();j++){
            if(nums[j] == 0){
                k--;
            }
            while(k<0){
                if(nums[i]==0){
                    k++;
                }
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans; 
    }
};