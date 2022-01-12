class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> arr;
        for(int i=0;i<n;i++)
        {
            vector<int> arrn(i+1);
            arrn[0]=1;
            arrn[i]=1;
            for(int j=1;j<i;j++)
            {
                arrn[j]=arr[i-1][j-1]+arr[i-1][j];
            }
            arr.push_back(arrn);
        }
        return arr;
    }
};