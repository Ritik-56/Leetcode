class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;

        // Find next greater element for every element in nums2
        for (int i = 0; i < nums2.size(); i++) {

            while (!st.empty() && nums2[i] > st.top()) {
                mp[st.top()] = nums2[i];
                st.pop();
            }

            st.push(nums2[i]);
        }

        // Elements remaining in stack have no greater element
        while (!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }

        // Build answer for nums1
        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};