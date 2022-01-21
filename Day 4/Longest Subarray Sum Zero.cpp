// Link to the problem:
https://bit.ly/31UHoeM

#include<bits/stdc++.h>
int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
    map<long,int> m;
    long s=0;
    int ans=0;
    for(int i=0;i<arr.size();i++){
        s+=arr[i];
        if(m.find(s)!=m.end())
        {
            ans=max(ans,i-m[s]);
        }
        else{
            m[s]=i;
        }
        if(s==0)
            ans=i+1;
    }

    return ans;
}