#include<bits/stdc++.h>
using namespace std;


int elements[1000005];
int query[1000005];
int h,l;
int binary_iterative_first(int low,int high,int value)
{

    int result=-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(elements[mid]==value)
        {
            result=mid;
            high=mid-1;
        }
        else if(elements[mid]>value) high=mid-1;
        else low=mid+1;
    }
    l=low;
    return result;

}

int binary_iterative_last(int low,int high,int value)
{

    int result=-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(elements[mid]==value)
        {
            result=mid;
            low=mid+1;
        }
        else if(elements[mid]>value) high=mid-1;
        else low=mid+1;
    }
    h=high;
    return result;

}

main()
{
    int n,q,d,query_name;
    int case_num;

    scanf("%d",&case_num);
    for(int j=1;j<=case_num;j++)
    {
        scanf("%d%d",&n,&q);
        for(int i=0; i<n; i++)
        {
          scanf("%d",&elements[i]);
        }

        printf("Case %d:\n",j);
        for(int i=0;i<q;i++){
            int s,e;
            scanf("%d%d",&s,&e);
            int start=binary_iterative_first(0,n-1,s);
            int end_=binary_iterative_last(0,n-1,e);
            if(start==-1 && end_==-1)
            {
                printf("%d\n",h-l+1);
            }
            else if(start==-1){

                printf("%d\n",end_-l+1);
            }
            else if(end_==-1){

                printf("%d\n",h-start+1);
            }
            else{

                printf("%d\n",end_-start+1);
            }
        }
    }

}
