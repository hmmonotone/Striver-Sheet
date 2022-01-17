//Link to the problem
//https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void rotate(vector<int>& nums, int i, int j){
        while(i<=j)
        {
            swap(nums[i++],nums[j--]);
        }
    }
    void nextPermutation(vector<int>& nums) {
        for(int i=nums.size()-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                int ind = i;
                for(int j=i;j<nums.size();j++)
                {
                    if(nums[j]<=nums[ind]&&nums[i-1]<nums[j])
                    {
                        ind=j;
                    }
                }
                swap(nums[ind],nums[i-1]);
                rotate(nums,i,nums.size()-1);
                return;
            }
        }
        rotate(nums,0,nums.size()-1);
    }
};
}
