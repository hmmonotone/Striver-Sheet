// Link to the problem:
// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    bool isPal(string s)
    {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                return 0;
            
            i++;
            j--;
        }
        return 1;
    }
    void helper(string s,int in,vector<vector<string>> &ans,vector<string> &t){
        if(in==s.size())
        {
            ans.push_back(t);
            return;
        }
        
        for(int j=in;j<s.size();j++)
        {
            if(isPal(s.substr(in,j-in+1)))
            {
                t.push_back(s.substr(in,j-in+1));
                helper(s,j+1,ans,t);
                t.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> t;
        helper(s,0,ans,t);
        return ans;
    }
};