class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int maxx = INT_MIN;
        int minn = INT_MAX;
        vector<int> mintillindex(n);
        for(int i = n-1;i>=0;i--){
            minn = min(minn,nums[i]);
            mintillindex[i] = minn;
        }
        for(int i=0;i<n;i++){
            maxx = max(maxx,nums[i]);
                if(maxx - mintillindex[i] <= k){
                    return i;
                }
            }
        return -1;
        }
};