// Link to the problem:
// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3)
            return {};
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> arr;
        for(int i=0;i<nums.size()-2;i++)
        {
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])) {
            int j=i+1,k=nums.size()-1;
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]<0)
                {
                    j++;
                }
                else if(nums[i]+nums[j]+nums[k]>0)
                {
                    k--;
                }
                else{
                    arr.push_back({nums[i],nums[j],nums[k]});
                    while(j<k&&nums[j]==nums[j+1])
                    j++;
                
                while(k>j&&nums[k]==nums[k-1])
                    k--;
                    
                    j++;
                    k--;
                }
                
            }
        }
        }
        return arr;
    }
};