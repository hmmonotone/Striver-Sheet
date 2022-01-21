// Link to the problem:
// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        
        set<int> st(nums.begin(),nums.end());
        int ans=1;
        for(auto x:nums){
            if(!st.count(x-1)){
                int c=1;
                int s=x+1;
                while(st.count(s))
                {
                    s++;
                    c++;
                }
                ans=max(ans,c);
            }
        }
        return ans;
    }
};