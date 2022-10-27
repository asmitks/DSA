
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> mp;
    
    while(n--) {
        string s;
        cin >> s;
        if(mp.find(s)==mp.end()) {
            cout << "OK" << endl;
            mp[s] = 0;
        } else {
            mp[s]++;
            cout << s << mp[s] << endl;
        }
        
    }
	// your code goes here
	return 0;
}


