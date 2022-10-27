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
#define V 100

int DFS_WHITE=-1,DFS_BLACK=1,DFS_GRAY=2;
vector <vii> ad;
int dfs_num[V],dfs_parent[V];
vi topo;

void dfs_visit(int a)
{
	cout<<a<<" ";
	dfs_num[a]=DFS_BLACK;
	TR(ad[a],i)
	{
		if(dfs_num[i->ff]==DFS_WHITE)
			dfs_visit(i->ff);
	}
}

void topo_sort(int a)
{
	dfs_num[a]=DFS_BLACK;
	TR(ad[a],i)
	{
		if(dfs_num[i->ff]==DFS_WHITE)
			topo_sort(i->ff);
	}
	topo.pb(a);
}

void graphCheck(int u) // DFS for checking graph edge properties...
{
	dfs_num[u] = DFS_GRAY; 
	TR (ad[u], v) 
	{ 
		if (dfs_num[v->first] == DFS_WHITE) 
		{ 
			printf(" Tree Edge (%d, %d)\n", u, v->first);
			dfs_parent[v->first] = u; 
			graphCheck(v->first);
		}
		else if (dfs_num[v->first] == DFS_GRAY) 
		{ 
			if (v->first == dfs_parent[u])
				printf(" Bidirectional (%d, %d) - (%d, %d)\n", u, v->first, v->first, u);
			else
				printf(" Back Edge (%d, %d) (Cycle)\n", u, v->first);
		}
		else if (dfs_num[v->first] == DFS_BLACK) 
			printf(" Forward/Cross Edge (%d, %d)\n", u, v->first);
	}
	dfs_num[u] = DFS_BLACK; 
}


int main() 
{ 
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
 	
	int n, e; 
	cin >> n >> e; 

	ad.assign(100,vii());
	memset(dfs_num,DFS_WHITE,sizeof(dfs_num));
	memset(dfs_parent,DFS_WHITE,sizeof(dfs_parent));
	topo.clear();
	REP(i,1,e)
	{
		int a,b;
		cin>>a>>b;
		ad[a].pb(mp(b,0));
	}
	
	REP(i,0,n-1)
		if(dfs_num[i]==DFS_WHITE)
			topo_sort(i);
	reverse(topo.begin(),topo.end());
	TR(topo,i)
		cout<<*i<<" ";

	return 0; 
} 
