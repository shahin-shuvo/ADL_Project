#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
int shouldBeIndex;
int binary(int a[],int hi,int lo,int x)
{
    int mid = lo+(hi-lo)/2;
    if(lo>hi){
        shouldBeIndex = ceil(double(lo+hi)/2);
        return -1;
    }
    if(a[mid]==x) return mid;
    else if(a[mid]>x)
        binary(a,mid-1,lo,x);  //  hi = mid-1;
    else if(a[mid]<x)
        binary(a,hi,mid+1,x);   //  lo = mid+1;
}
main()
{
    int n,q,x,arr[50005];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>q;
    long long int query[100000];
    for(int i=0;i<q;i++)
    {
        cin>>query[i];
    }
    int val;
    for(int i=0;i<q;i++)
    {
        val = 0;
        val = binary(arr,n-1,0,query[i]-1);
        if(val != -1) cout<<arr[val]<<" ";
        else if(shouldBeIndex-1<0)printf("X ");
        else printf("%d ",arr[shouldBeIndex-1]);
        val = 0;
        val = binary(arr,n-1,0,query[i]+1);
        if(val != -1) cout<<arr[val];
        else if(shouldBeIndex==n)printf("X");
        else printf("%d",arr[shouldBeIndex]);
        cout<<endl;
    }


}
