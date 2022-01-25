// Link to the problem:
// https://bit.ly/3nquVHj

int findMinimumCoins(int amount) 
{
    // Write your code here
    int coins[]={1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int ans=0;
    for(int i=8;i>=0&&amount!=0;i--)
    {
        if(coins[i]<=amount)
        {
            int t=amount/coins[i];
            amount-=(coins[i]*t);
            ans+=t;
        }
    }
    return ans;
}
