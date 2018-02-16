#include<bits/stdc++.h>
using namespace std;
#define max 100

struct BFS
{
    int vertex,edge;

    vector<int>List[max];

    int vis[max],level[max];

    BFS()
    {
        memset(level,-1,sizeof(level));
        memset(vis,0,sizeof(vis));
    }


    void insert_list(int u,int v)
    {
        List[u].push_back(v);
    }

    void dfs(int u)
    {
        vis[u]=1;

        for(int i=0;i<List[u].size();i++)
        {
            int t=List[u][i];
            if(!vis[t])
                dfs(t);
        }
    }
};
main()
{
    BFS b;
    int i,u,v,j,c=0,k;
    int a[100];
    memset(a,0,sizeof(a));
    cin>>b.vertex;
    for(i=1; i<=b.vertex; i++)
    {
        cin>>u>>v;
        b.insert_list(u,v);
    }
    for(i=1;i<=b.vertex;i++)
    {
        c=0;
        b.dfs(i);
        for(j=1;j<=b.vertex;j++)
        {
            if(b.vis[i]==1) c++;
        }
        cout<<c<<endl;
        a[i]=c;
        memset(b.vis,0,sizeof(b.vis));
    }
    int t=-1;

    for(i=0;i<100;i++)
        {
		if(a[i]>t)

			{
			    t=a[i];
			    k=i;
			}

	}
	cout<<k<<endl;
}
