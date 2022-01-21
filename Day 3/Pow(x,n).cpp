// Link to the problem
// https://leetcode.com/problems/powx-n/

class Solution {
public:
    double helper(double x,int n) {
        if(n==0)
            return 1;
        
        double ans = myPow(x,n/2);
        if(n%2==0)
        {
            return ans*ans;
        }
        return ans*ans*x;
    }
    double myPow(double x, int n) {
        double ans = helper(x,abs(n));
        if(n<0)
            return 1/ans;
        
        return ans;
    }
};