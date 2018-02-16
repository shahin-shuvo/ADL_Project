#include<bits/stdc++.h>
using namespace std;

#define inf -100
#define nil -1
#define white 0
#define red 1
#define blue 2


struct breadth
{
    vector < int > v[100];
    int node,edge;
    int color[100],prev[100],l[100];

    bool bicoloring(int src)
    {
        int i;

        memset(color,white,sizeof(color));

        color[src]=red;

        queue < int > q;
        q.push(src);

        while(!q.empty())
        {
            int t = q.front();
            q.pop();

           for(auto &u:v[t])
            {
                if(color[u]==white)
                {
                    if(color[t]==red)
                        color[u]=blue;
                    else
                        color[u]=red;
                    q.push(u);
                }
                if(color[t]==color[u])
                    return false;
            }

        }
        return true;
    }

};

int main()
{
    breadth ds;
    int i,j,a,b,u,v;
    cin>>ds.node>>ds.edge;

    for(i=0;i<ds.edge;i++)
    {
        cin>>a>>b;
        ds.v[a].push_back(b);
        ds.v[b].push_back(a);

    }

    bool bi=ds.bicoloring(1);

    if(bi==true)
        cout<<"Possible"<<endl;
    else
        cout<<"Impossible"<<endl;

    return 0;
}
