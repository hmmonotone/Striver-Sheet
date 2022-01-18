// Link to the problem
// https://bit.ly/339fFb7

int countinversion(long long * arr ,int left ,int mid, int right)
{
    int leftlen= (mid-left+1);
    int rightlen=(right-mid);
    long long  ans=0;
    int * leftsubarray= new int[leftlen]{0};
    int * rightsubarray = new int[rightlen]{0};
    for(int i=0;i<leftlen;i++)
    {
       leftsubarray[i]=arr[left+i]; 
    }
    for(int j=0;j<rightlen;j++)
    {
        rightsubarray[j]= arr[mid+1+j];
    }
    int l=0;
    int r=0;
    int index=left;
    while(l<leftlen and r<rightlen)
    {
        if(leftsubarray[l]<=rightsubarray[r])
        {
            arr[index++]= leftsubarray[l];
            l++;
        }
        else
        {
            arr[index++]=rightsubarray[r];
            r++;
            ans+=(leftlen-l);
        }
    }
    while(l<leftlen)
    {
        arr[index++]=leftsubarray[l++];
    }
    while(r<rightlen)
    {
        arr[index++]=rightsubarray[r++];
    }
    
    return ans;
}
 long long cal(long long * arr ,int left,int right)
 {
     long long  count=0;
     if(left<right)
     {
          int mid= left+(right-left)/2;
         count+= cal(arr,left,mid);
         count+= cal(arr,mid+1,right);
        count+= countinversion(arr ,left,mid,right);
     }
  
     return count;
 }

long long getInversions(long long *arr, int n){
    long long ans=0;
    ans= cal(arr,0,n-1);
    
    return ans;
}