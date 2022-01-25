// Link to the problem:
// https://bit.ly/3npx0mW

int calculateMinPatforms(int at[], int dt[], int n) {
    int ans=1,c=1;
    sort(at,at+n);
    sort(dt,dt+n);
    int i=1,j=0;
    while(i<n&&j<n)
    {
        if(at[i]<=dt[j])
        {
            c++;
            i++;
        }
        else{
            c--;
            j++;
        }
        ans=max(ans,c);
    }
    return ans;
}