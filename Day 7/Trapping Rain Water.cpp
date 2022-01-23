// Link to the problem:
// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n,0),right(n,0);
        int maxl=INT_MIN,maxr=maxl;
        for(int i=0;i<n;i++)
        {
            maxl=max(maxl,height[i]);
            maxr=max(maxr,height[n-i-1]);
            left[i]=maxl;
            right[n-i-1]=maxr;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=(min(left[i],right[i])-height[i]);
        }
        return ans;
    }
};