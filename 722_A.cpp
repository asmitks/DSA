#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a.begin(),a.end());
        int ans = a[0]|a[1];
        for(int i=2;i<n;i++)
            ans = ans|a[i];
        cout<<ans<<"\n";
    }
}
