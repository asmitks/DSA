// Belamn Ford shortest path algorithm implementation in C++14

#include<bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    
    vector<pair<int,int>> adj[n];
    
    for(int i=0; i<m; i++)
    {
        int a,b,w;
        cin >> a >> b >> w;
        a--,b--;
        
        adj[a].pb({b,w});
        // adj[b].pb({a,w});
    }
    
    int m_dist[n];
    
    for(int i=1; i<n; i++)
        m_dist[i] = INT_MAX;
    m_dist[0] = 0;
    set<pair<int,int>> active;
    active.insert({0,0});
    while(!active.empty())
    {
        int where = active.begin()->second;
        active.erase(active.begin());
        for(auto vertex: adj[where])
        {
            if(m_dist[vertex.first] > m_dist[where] + vertex.second)
            {
                active.erase({m_dist[vertex.first],vertex.first});
                m_dist[vertex.first] = vertex.second + m_dist[where];
                active.insert({m_dist[vertex.first],vertex.first});
            }
        }
    }
    
    for(int i=1; i<n; i++)
        printf("%d ",m_dist[i]);
    return 0;
}