Link to the problem:
https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++)
            {
                int k=j+1,l=nums.size()-1;
            while(k<l)
            {
                long t=(long)nums[k]+(long)nums[l]+(long)nums[i]+(long)nums[j];
                if(t<target)
                {
                    k++;
                }
                else if(t>target)
                {
                    l--;
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                    while(k+1<=l&&nums[k]==nums[k+1])
                        k++;
                    while(l-1>=k&&nums[l]==nums[l-1])
                        l--;
                    
                    k++;
                    l--;
                }
            }
                while(j+1<nums.size()&&nums[j]==nums[j+1])
            {
                j++;
            }
            }
            while(i+1<nums.size()&&nums[i]==nums[i+1])
            {
                i++;
            }
        }
        return ans;
    }
};