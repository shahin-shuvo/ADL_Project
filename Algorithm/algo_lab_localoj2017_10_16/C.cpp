#include<bits/stdc++.h>
using namespace std;

struct website
{
    int time,webtype;
    website(int time,int webtype):time(time),webtype(webtype) {}
    bool operator<(const website &p) const
    {
        if(time==p.time) return webtype<p.webtype;
        return time<p.time;
    }
};

vector<website> vec;
main()
{
    int test,t=0;
    cin>>test;
    while(test--)
    {
        int n,b;
        cin>>n;
        vec.clear();
        for(int i=0; i<n; i++)
        {
            cin>>b;
            vec.push_back(website(b,0));

        }
        for(int i=0; i<n; i++)
        {
            cin>>b;
            vec.push_back(website(b,1));

        }
        sort(vec.begin(),vec.end());
        int result=0,current=0;
        for(int i=0; i<vec.size(); i++)
        {
            if(vec[i].webtype==0) current++;
            else current--;
            result = max(result,current);
        }
        cout<<"Case "<<++t<<": "<<result<<endl;
    }
}
