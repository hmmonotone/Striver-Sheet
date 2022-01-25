// Link to the problem:
// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    void helper(int i, int target, vector<int> &arr, vector<int> &can,vector<vector<int>> &ans)
    {
        if(i==can.size()&&target==0)
        {
            ans.push_back(arr);
            return;
        }
        if(i==can.size())
        {
            return;
        }
        if(target==0)
        {
            ans.push_back(arr);
            return;
        }
        if(target<0)
            return;
        
        arr.push_back(can[i]);
        helper(i,target-can[i],arr,can,ans);
        arr.pop_back();
        helper(i+1,target,arr,can,ans);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        helper(0,target,arr,can,ans);
        return ans;
    }
};