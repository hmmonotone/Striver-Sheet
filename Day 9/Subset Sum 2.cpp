// Link to the problem:
// https://leetcode.com/problems/subsets-ii/submissions/

class Solution {
public:
    void helper(vector<int> &nums, int in,vector<int>&t, vector<vector<int>> &ans)
    {
        for(int i=in;i<nums.size();i++)
        {
            if(i!=in&&nums[i]==nums[i-1])continue;
            else{
                t.push_back(nums[i]);
                ans.push_back(t);
                helper(nums,i+1,t,ans);
                t.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> t;
        vector<vector<int>> ans;
        ans.push_back({});
        sort(nums.begin(),nums.end());
        helper(nums,0,t,ans);
        return ans;
    }
};