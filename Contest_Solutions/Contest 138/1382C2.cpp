//░░░░░░░░░░▄
//░░░░░░░░▄▐░▄▄█████▄▄
//░░░░░░▄█████████████▄▀▄▄░▄▄▄
//░░░░░█████████████████▄██████
//░░░░████▐█████▌████████▌█████▌
//░░░████▌█████▌█░████████▐▀██▀
//░▄█████░█████▌░█░▀██████▌█▄▄▀▄
//░▌███▌█░▐███▌▌░░▄▄░▌█▌███▐███░▀
//▐░▐██░░▄▄▐▀█░░░▐▄█▀▌█▐███▐█
//░░███░▌▄█▌░░▀░░▀██░░▀██████▌
//░░░▀█▌▀██▀░▄░░░░░░░░░███▐███
//░░░░██▌░░░░░░░░░░░░░▐███████▌
//░░░░███░░░░░▀█▀░░░░░▐██▐███▀▌
//░░░░▌█▌█▄░░░░░░░░░▄▄████▀░▀
//░░░░░░█▀██▄▄▄░▄▄▀▀▒█▀█░▀
//░░░░░░░░░▀░▀█▀▌▒▒▒░▐▄▄
//░░░░░░░░▄▄▀▀▄░░░░░░▄▀░▀▀▄▄
//░░░░░░▄▀░▄▀▄░▌░░░▄▀░░░░░░▄▀▀▄
//░░░░░▐▒▄▀▄▀░▌▀▄▄▀░░░░░░▄▀▒▒▒▐
//░░░░▐▒▒▌▀▄░░░░░▌░░░░▄▄▀▒▐▒▒▒▒▌
//░░░▐▒▒▐░▌░▀▄░░▄▀▀▄▀▀▒▌▒▐▒▒▒▒▐▐
//░░░▌▄▀░░░▄▀░█▀▒▒▒▒▀▄▒▌▐▒▒▒▒▒▌▌
//░░▄▀▒▐░▄▀░░░▌▒▐▒▐▒▒▒▌▀▒▒▒▒▒▐▒▌
#include<bits/stdc++.h>
using namespace std; 
#define ff first
#define ss second
#define pb push_back
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define ll unsigned long long
#define mp make_pair 
#define INF INT_MAX
#define NIL 0

int main() { 
	fast_io();
	long long t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int v[n];
		int b[n];
		string s;
		cin>>s;
		for(int i=0;i<n;i++)
			if(s[i] == '1')
				v[i] = 1;
			else
				v[i] = 0;
		cin>>s;
		for(int i=0;i<n;i++)
			if(s[i] == '1')
				b[i] = 1;
			else
				b[i] = 0;
		int k = n-1;
		int f = 0;
		bool flip = false;
		// cout<<"input complete\n";
		vector<int> answer;
		for(int i=n-1;i>0;i--) {
			if((v[k] == b[i] and flip) or (v[k] != b[i] and !flip)){
				// cout<<"in if "<<i<<" "<<k<<" "<<flip<<endl;
				if(v[k] != v[f]) {
					answer.push_back(1);
					if(v[f] == 1)
						v[f] = 0;
					else
						v[f] = 1;
				}
				answer.push_back(i+1);
				if(flip) {
					int temp = f;
					f = k;
					k = temp-1;
					flip = false;
				}
				else {
					int temp = f;
					f = k;
					k = temp+1;
					flip = true;
				}
			}
			else {
				if(flip)
					k++;
				else
					k--;
			}
		}
		if((v[f] == b[0] and flip) or (v[f] != b[0] and !flip))
			answer.push_back(1);
		cout<<answer.size()<<" ";
		for(auto x : answer)
			cout<<x<<" ";
		cout<<endl;
	}
	return 0;
}
