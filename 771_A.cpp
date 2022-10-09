#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n);
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) {
            cin>>a[i];
            v.push_back({a[i],i});
        }
        // for(auto i:a)
        //     cout<<i<<" ";
        // cout<<"\n";
        sort(v.begin(),v.end());
        int l = -1,r=-1;
        for(int i=0;i<n;i++)
            if(v[i].second != i) {
                l = i;
                r = v[i].second;
                break;
            }

        // cout<<l<<" - "<<r<<"\n";
        if(l!=-1)
            reverse(a.begin()+l,a.begin()+r+1);
        for(auto i:a)
            cout<<i<<" ";
        cout<<"\n";
        // cout<<"\n\n";
    }
}
