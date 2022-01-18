// Link to the problem
// https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0,k=i;j<matrix.size()&&k<matrix.size();j++,k++)
            {
                swap(matrix[j][k],matrix[k][j]);
            }
        }
        for(int i=0,j=matrix.size()-1;i<=j;i++,j--)
        {
            for(int k=0;k<matrix.size();k++)
            {
                swap(matrix[k][i],matrix[k][j]);
            }
        }
    }
};