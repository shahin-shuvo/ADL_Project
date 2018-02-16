#include<bits/stdc++.h>
using namespace std;

vector<int> v;
void B(int s)
{
    int n,x;
    v.clear();
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        v.push_back(x);
    }
    reverse(v.begin(),v.end());
    for(int i=0; i<n; i++)
    {
        if(v.size()==1) break;
        int last = v.front();
        v.erase(v.begin()+0);
        v.push_back(last);
        if(i<v.size())
        {
            v.erase(v.begin()+i);
        }
        else v.pop_back();
    }
    cout<<"Case "<<s<<": "<<v.front()<<endl;
}
main()
{
    int test , s=0;
    cin>>test;
    while(test--)
    {
        B(++s);
    }
}
