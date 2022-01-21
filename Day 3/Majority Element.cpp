// Link to the problem
// https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=nums[0],c=1;
        for(int i=0;i<nums.size();i++)
        {
            if(ans==nums[i])
                c++;
            else
                c--;
            
            if(c==0)
            {
                ans=nums[i];
                c=1;
            }
        }
        return ans;
    }
};