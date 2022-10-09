#include "bits/stdc++.h"

using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 

#define ll long long
#define ff first
#define ss second   
#define pb push_back
#define mp  make_pair
typedef vector<ll> vi;
typedef pair<ll, ll> ii; 
typedef vector<ii> vii;
#define TR(c, it) for (auto it = (c).begin(); it != (c).end(); it++)
#define REP(i,a,b) for(int i=int(a);i<=int(b);i++)

// Templates
template <class T> ostream& operator << (ostream &os, const vector<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T> ostream& operator << (ostream &os, const set<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T, class S> ostream& operator << (ostream &os, const pair<T, S> &v) { os << v.first << ' ' << v.second; return os; }
template <class T, class S> ostream& operator << (ostream &os, const unordered_map<T, S> &v) { for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' '; return os; }

#define TRACE
#ifndef ONLINE_JUDGE
#define tr(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define tr(...)
#endif


// template <typename T>
// using indexed_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template <typename T>
using max_heap = priority_queue<T>;
 
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;



int main()
{
	// ifstream fin ('input.txt');
	// ofstream fout ('output.txt');
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt", "w", stderr);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		vi h(n),k(n);
		REP(i,0,n-1)
			cin>>k[i];
		REP(i,0,n-1)
			cin>>h[i];
		vector<pair<ll,ll>> v;
		REP(i,0,n-1)
			v.pb({k[i]-h[i],k[i]});
		sort(v.begin(),v.end());
		ll l = -1,r=-1,ans=0;
		REP(j,0,n-1) {
			if(v[j].ff >= r) {
				ans += ((r-l)*(r-l+1))/2;
				l  = v[j].ff;
				r = v[j].ss;
			}
			else
				r = max(r,v[j].ss);
		}
		ans += ((r-l)*(r-l+1))/2;
		cout<<ans<<"\n";
	}
	return 0;
}
