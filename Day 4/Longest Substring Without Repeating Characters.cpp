// Link to the problem:
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> temp(256,-1);
        int i=0,j=0,len=0;
        while(j<s.size())
        {
            if(temp[s[i]]!=-1)
            {
                i=max(temp[s[j]]+1,i);
            }
            temp[s[j]]=j;
            len=max(len,j-i+1);
            j++;
        }
        return len;
    }
};