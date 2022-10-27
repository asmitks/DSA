#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double 
#define pr 1000000007 
#define ff first
#define ss second
#define pb push_back
#define mp	make_pair
typedef vector<int> vi;
typedef pair<int, int> ii; 
typedef vector<ii> vii;
#define TR(c, it) for (auto it = (c).begin(); it != (c).end(); it++)
#define REP(i,a,b) for(int i=int(a);i<=int(b);i++)
#define MAXN 5000001
#define inf 1e9+500

vector<vii> ad;

int main()
{
	// ifstream fin ("input.txt");
	// ofstream fout ("output.txt");
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

	ad.assign(10020,vii());
	int INF=2e9;
	int V,E;
	cin>>V>>E;
	REP(i,1,E)
	{
		int a,b,c;
		cin>>a>>b>>c;
		ad[a].pb(mp(b,c));
	}
	vector<int> dist(V+1, INF); 
	dist[1] = 0;
	
	priority_queue<ii, vector<ii>, greater<ii> > pq; 
	pq.push(ii(0, 1)); 
	while (!pq.empty()) 
	{
		ii top = pq.top(); 
		pq.pop(); 
		int d = top.first, u = top.second;
		if (d == dist[u]) 
			TR(ad[u], it) 
			{	 
				int v = it->first, weight_u_v = it->second;
				if (dist[u] + weight_u_v < dist[v]) 
				{	
					dist[v] = dist[u] + weight_u_v; 
					pq.push(ii(dist[v], v));

				}
			} 
	}
	
	/*
	REP (i, 0, V - 1) // relax all E edges V-1 times, O(V)
		REP (u, 0, V - 1) // these two loops = O(E)
			TR(ad[u], v) // has edge and can be relaxed
				dist[v->first] = min(dist[v->first], dist[u] + v->second);
	*/
	REP(i,2,V)
		cout<<dist[i]<<" ";
	cout<<endl;
	return 0;
}

