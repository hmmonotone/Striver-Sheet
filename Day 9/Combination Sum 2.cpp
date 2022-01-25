// Link to the problem:
// https://leetcode.com/problems/combination-sum-ii/

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
        
        
        helper(i+1,target-can[i],arr,can,ans);
        arr.pop_back();
        while(i+1<can.size()&&can[i]==can[i+1])
            i++;
        helper(i+1,target,arr,can,ans);
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(can.begin(),can.end());
        helper(0,target,arr,can,ans);
        return ans;
    }
};