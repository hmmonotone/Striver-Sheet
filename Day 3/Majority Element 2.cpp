// Link to the problem
// https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size()==1)
            return nums;
        int nums1=nums[0],nums2=nums[1],c1=0,c2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums1==nums[i])
                c1++;
            else if(nums2==nums[i])
                c2++;
            else if(c1==0){
                c1=1;
                nums1=nums[i];
            }
            else if(c2==0)
            {
                c2=1;
                nums2=nums[i];
            }
            else{
                c1--;
                c2--;
            }
        }
        c1=0,c2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==nums1)
                c1++;
            else if(nums[i]==nums2)
                c2++;
        }
        if(c1>(nums.size()/3)&&c2>(nums.size()/3))
        {
            return {nums1,nums2};
        }
        if(c1>(nums.size()/3))
        {
            return {nums1};
        }
        if(c2>(nums.size()/3))
        return {nums2};
        
        return {};
    }
};