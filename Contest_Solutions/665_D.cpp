#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define fastIO() ios_base::sync_with_stdio(false);  cin.tie(NULL);  cout.tie(NULL); 
#define endl '\n'
#define all(a) a.begin(),a.end()

#define TRACE
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

template <typename T>
using ordered_set =tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T> ostream& operator << (ostream &os, const vector<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T> ostream& operator << (ostream &os, const set<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T, class S> ostream& operator << (ostream &os, const pair<T, S> &v) { os << v.first << ' ' << v.second; return os; }
template <class T, class S> ostream& operator << (ostream &os, const unordered_map<T, S> &v) { for (auto i : v) os << '(' << i.first << " => " << i.second << ')' << ' '; return os; }
template <class T, class S> ostream& operator << (ostream &os, const map<T, S> &v) { for (auto i : v) os << '(' << i.first << " => " << i.second << ')' << ' '; return os; }

const long long MAXN = 2*1e6 + 10;
const long long mod = 1e9 + 7;
long long t;

vector<long long> adj[MAXN + 1]; 
bool vis[MAXN + 1]; 
long long ans[MAXN+1];
 
long long dfs(long long root){
    vis[root] = true;
    ans[root] = 1;
    for(auto x:adj[root]){
        if(!vis[x]){
            ans[root] = (ans[root] + dfs(x));
        }
    }
    return ans[root];
}

inline long long mulmod(long long  a, long long b, long long c) {
    return (a%c * b%c)%c;
}

// Testcase
void testcase(){
	long long n;
	cin>>n;
	long long x,y;
	for(long long i=0;i<n+1;i++){
		adj[i] = {};
		vis[i] = 0;
		ans[i] = 0;
	}
	for(long long i=0;i<n-1;i++){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	long long m; cin>>m;
	long long b[m];
	for(long long i=0;i<m;i++){
		cin>>b[i];
	}
	dfs(1);
	vector<long long> t;
	for(long long i=2;i<=n;i++){
		t.push_back(ans[i]);
	}
	sort(b, b+m,greater<long long>());
	for(long long i=0;i<n-1;i++){
		t[i] = t[i]*(n-t[i]);
	}
	sort(all(t),greater<long long>());
	long long val = 0;
	if(m==n-1){
		for(long long i=0;i<n-1;i++){
			val = (val%mod + mulmod(t[i],b[i],mod)%mod + mod)%mod;
		}
		cout<<val<<endl;
		return;
	}
	else if(m>n-1){
		long long k = m-n+2;
		long long pr = 1;
		for(long long i=0;i<k;i++){
			pr = (pr*b[i])%mod;
		}
		b[k-1] = pr;
		vector<long long> temp;
		for(long long i=k-1;i<m;i++){
			temp.push_back(b[i]);
		}
		for(long long i=0;i<n-1;i++){
			val = (val%mod + mulmod(t[i],temp[i],mod)%mod + mod)%mod;
		}
		cout<<val<<endl;
		return;
	}
	else{
		for(long long i =0;i<m;i++){
			val = (val%mod + mulmod(t[i],b[i],mod)%mod + mod)%mod;
		}
		for(long long i=m;i<n-1;i++){
			val = (val%mod + t[i]%mod)%mod;
		}
		cout<<val<<endl;
		return;
	}
}
							
//  Main
signed main(){
    fastIO();
    // t = 1;
    cin>>t;
    while(t--){
        testcase();
    }
    return 0;
}
