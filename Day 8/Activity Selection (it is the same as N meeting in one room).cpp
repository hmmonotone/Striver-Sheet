// Link to the problem:
// https://bit.ly/3I2iPvN

#include<bits/stdc++.h>
bool helper(pair<int,int> a, pair<int,int> b){
    if(a.second!=b.second)
    return a.second<b.second;
    
    return (a.second-a.first)<(b.second-b.first);
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    vector<pair<int,int>> arr;
    for(int i=0;i<start.size();i++)
    {
        arr.push_back({start[i],finish[i]});
    }
    sort(arr.begin(),arr.end(),helper);
    int ans=1,s=arr[0].first,e=arr[0].second;
    for(int i=1;i<arr.size();i++)
    {
        if(e<=arr[i].first)
        {
            ans++;
            e=arr[i].second;
        }
    }
    return ans;
}