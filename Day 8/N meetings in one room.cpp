// Link to the problem:
// https://bit.ly/3zXdqn5

#include<bits/stdc++.h>
using namespace std;

bool helper(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
    if(a.second.second!=b.second.second)
        return a.second.second<b.second.second;
    else{
        return a.first<b.first;
    }
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    vector<pair<int,pair<int,int>>> arr;
    for(int i=0;i<start.size();i++)
    {
        arr.push_back({i+1,{start[i],end[i]}});
    }
    sort(arr.begin(),arr.end(),helper);
    vector<int> ans;
    ans.push_back(arr[0].first);
    int s=arr[0].second.first,e=arr[0].second.second;
    for(int i=1;i<arr.size();i++)
    {
        if(e<arr[i].second.first)
        {
            ans.push_back(arr[i].first);
            e=arr[i].second.second;
        }
    }
    return ans;
}