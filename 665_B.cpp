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

const int MAXN = 2*1e6 + 10;
const int mod = 1e9 + 7;
int t;

// Testcase
void testcase(){
	int x1,y1,z1;
	int x2,y2,z2;
	cin>>x1>>y1>>z1;
	cin>>x2>>y2>>z2;
	int twos = min(z1,y2);
	z1 -= twos;
	y2 -= twos;
	int off = 0;
	if(y1>x2+y2){
		off = y1 - x2- y2;
	}
	cout<<twos*2 - 2*off<<endl;
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
