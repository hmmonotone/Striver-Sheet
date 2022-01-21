// Link to the problem
// https://leetcode.com/problems/search-a-2d-matrix/submissions/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0,j=matrix[0].size()-1;
        while(i>=0&&i<matrix.size()&&j>=0&&j<matrix[0].size())
        {
            if(matrix[i][j]<target)
            {
                i++;
            }
            else if(matrix[i][j]>target)
            {
                j--;
            }
            else{
                return 1;
            }
        }
        return 0;
    }
};