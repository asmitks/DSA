#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll n;
    cin >> n;
    while(n--) {
        ll t;
        cin >> t;
        ll a[t];
        map<ll,ll> mp;
        for(ll i = 0; i < t; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }
        priority_queue<ll> pq;
        for(auto x : mp) {
            pq.push(x.second);
        }
        ll ans = 0;
        
        while(pq.size() >= 2) {
            ll p = pq.top();
            pq.pop();
            ll q = pq.top();
            pq.pop();
            p--;
            q--;
            if(p) {
                pq.push(p);
            } if(q) {
                pq.push(q);
            }
            
        }
        if(!pq.empty()) {
        ans =  pq.top();
        }
         cout << ans << endl;
    }
   
	// your code goes here
	return 0;
}

