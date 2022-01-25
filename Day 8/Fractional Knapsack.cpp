// Link to the problem:
// https://bit.ly/3I7fNXn

#include<bits/stdc++.h>
using namespace std;

bool helper(pair<int,int> a, pair<int,int> b){
    double a1= (double)a.second/(double)a.first;
    double a2= (double)b.second/(double)b.first;
    return a1>a2;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(),items.end(),helper);
    double ans=0;
    for(int i=0;i<items.size();i++)
    {
        if(items[i].first<=w)
        {
            ans+=items[i].second;
            w-=items[i].first;
        }
        else{
            double t=items[i].second;
            t/=items[i].first;
            t*=w;
            ans+=t;
            break;
        }
    }
    return ans;
}