// Link to the problem:
// https://bit.ly/3Gs6wZu

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    int xo = 0;
    for(int i=0;i<arr.size();i++)
    {
        xo=xo^arr[i];
    }
    for(int i=1;i<=arr.size();i++)
    {
        xo=xo^i;
    }
    int t=xo&~(xo-1);
    int lb=0,rb=0;

    for(int i=0;i<n;i++){
        if(arr[i]&t)
        {
            lb=lb^arr[i];
        }
        else{
            rb=rb^arr[i];
        }
    }
    for(int i=1;i<=n;i++){
        if(i&t)
            lb=lb^i;
        else    
        rb=rb^i;
    }
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==rb)
            c++;
    }
    if(c==2)
        return {lb,rb};
    
    return {rb,lb};
}
