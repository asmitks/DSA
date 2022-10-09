#include <bits/stdc++.h>
using namespace std;
#define MOD		1000000007
#define ll		long long int
#define endl	"\n"
 
#define fastio 	ios_base::sync_with_stdio(false);cin.tie(NULL)
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
 
 
 
void solve() {
	ll t;
	cin >> t;
	ll a[t];
	for (int i = 0; i < t; i++) {
	    cin >> a[i];
	}
	vector<pair<ll,ll>> init;
	
 
	
	for(int i = 0; i < t; i++) {
	    init.push_back(make_pair(a[i],i));
	}
	sort (a, a+t);
	sort(init.begin(),init.end());
	ll prefix [t] = {0};
	prefix [0] = a[0];
	for (int i = 1; i < t; i++) {
	    prefix[i] = prefix[i-1] + a[i];
	}
	ll index = -1;
	vector<ll> ans;
	for (int i = 0; i < t - 1; i++) {
	    if(prefix[i] < a[i+1])
	        index = i;
	}
	for (int i = index + 1; i < t; i++) {
	    ans.push_back(init[i].second + 1);
	}
	sort (ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (ll i : ans) {
	    cout << i << " ";
	}
	cout << endl;
	
 
}
 
 
int main() {
	fastio;
	#ifndef ONLINE_JUDGE
 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n;
	cin >> n;
	while(n--) {
		solve();
	}
}
