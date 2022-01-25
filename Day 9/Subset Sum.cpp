// Link to the problem
// https://practice.geeksforgeeks.org/problems/subset-sums2234/1

// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        if(N==0)
        return {0};
        
        vector<int> temp=subsetSums(arr,N-1);
        
        int n=temp.size();
        for(int i=0;i<n;i++)
        {
            temp.push_back(temp[i]+arr[N-1]);
        }
        return temp;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends