// Link to the problem:
// https://bit.ly/3K9XZfV

#include<bits/stdc++.h>
using namespace std;
bool helper(vector<int> a,vector<int> b){
//     if(a[1]!=b[1])
        return a[1]>b[1];
//     else
//         a[0]<b[0];
    
//     if(a[0]!=b[0])
//     return 
//     else
//         return a[1]>b[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    sort(jobs.begin(),jobs.end(),helper);
    int time=0;
    int ans=0;
    int n=0;
    for(int i=0;i<jobs.size();i++)
    {
        n=max(n,jobs[i][0]);
    }
    vector<int> t(n,-1);
    set<int,greater<int>> st;
    for(int i=1;i<=n;i++)
        st.insert(i);
    
    for(int i=0;i<jobs.size();i++)
    {
        if (st.size() == 0 || jobs[i][0] < *st.rbegin())
        {
            continue;
        }

        int s = *st.lower_bound(jobs[i][0]);
        ans += jobs[i][1];
        st.erase(s);
    }
    return ans;
}
