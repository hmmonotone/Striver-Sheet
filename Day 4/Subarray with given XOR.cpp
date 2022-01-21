// Link to the problem:
// https://www.interviewbit.com/problems/subarray-with-given-xor/

int Solution::solve(vector<int> &A, int B) {
    int f=0;
    int xo=0;
    unordered_map<int,int> m;
    for(int i=0;i<A.size();i++){
        xo=xo^A[i];
        if(xo==B)
        f++;
        int t=xo^B;
        if(m.find(t)!=m.end())
        {
            f=f+m[t];
        }
        m[xo]++;
    }
    return f;
}