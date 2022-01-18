// Link to the problem
// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intr) {
        sort(intr.begin(),intr.end());
        vector<vector<int>> ans;
        int s=intr[0][0],e=intr[0][1];
        for(int i=0;i<intr.size();i++)
        {
            if(intr[i][0]>e)
            {
                ans.push_back({s,e});
                s=intr[i][0];
                e=intr[i][1];
            }
            else{
                e=max(intr[i][1],e);
            }
        }
        ans.push_back({s,e});
        return ans;
    }
};