#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

main()
{
    int n,q,cas=1,x;
    vector<int>m;
    vector<int>r;
    pair<vector<int>::iterator,vector<int>::iterator>it;
    while(scanf("%d %d",&n,&q)&&(n||q))
    {

        m.clear();
        r.clear();
        for(int i =0; i<n; i++)
        {
            scanf("%d",&x);
            m.push_back(x);
        }
        for(int i =0; i<q; i++)
        {
            scanf("%d",&x);
            r.push_back(x);
        }
        sort(m.begin(),m.end());
        int siz = r.size();
        cout<<"CASE# :"<<cas<<endl;
        for(int i=0; i<siz; i++)
        {
            if(binary_search(m.begin(),m.end(),r[i]))
            {
                it = equal_range(m.begin(), m.end(), r[i]);
                printf("%d found at %d\n", r[i], (it.first - m.begin()) + 1);

            }
            else
            {
                printf("%d not found\n", r[i]);
            }

        }

        cas++;
    }
}
