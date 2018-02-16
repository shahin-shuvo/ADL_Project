/*
*  Code By : Pritish Thakkar
*  Tags : Graph Traversal + DFS
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll temp[105];
vector<ll> g[105];
bool color[105];
ll ans=0,k=0;

void dfs(ll num){
    ll maxi=0,next=-1;
    color[num] = true;
    for(ll i=0;i<g[num].size();i++){
        ll cur_i = g[num][i];
        if(!color[cur_i]){
            if(temp[cur_i] > maxi){
                maxi = temp[cur_i];
                next = cur_i;
            }
        }
    }
    if(next != -1) {k=next;ans+=maxi;dfs(next);}
    return;
}

int main(){
    ll t,counter=0;
    cin>>t;
    while(t--){
        ll n,m,x,a,b;
        cin>>n>>m;
        for(ll i=0;i<n;i++){
            cin>>temp[i];
        }
        for(ll i=0;i<m;i++){
            cin>>a>>b;
            g[a].push_back(b);
        }
        /*
        ADJACENCY LIST :
        for(ll i=0;i<n;i++){
            for(ll j=0;j<g[i].size();j++){
                cout<<g[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        memset(color,false,sizeof(color));
        ans=0;
        dfs(0);
        cout<<"Case "<<++counter<<": "<<ans<<" "<<k<<endl;
        for(ll i=0;i<n;i++) g[i].clear();
    }

}
