// Link to the problem
// https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            ans[i][0]=1;
        }
        for(int j=0;j<n;j++)
        {
            ans[0][j]=1;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                ans[i][j]=ans[i][j-1]+ans[i-1][j];
            }
        }
        return ans[m-1][n-1];
    }
};