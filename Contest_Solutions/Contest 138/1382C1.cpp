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
		// cout<<"input complete\n";
		vector<int> answer;
		for(int i=n-1;i>0;i--) {
			if(v[i] != b[i]) {
				if(v[i] != v[0]) {
					answer.push_back(1);
					if(v[0] == 1)
						v[0] = 0;
					else
						v[0] = 1;
				}
				answer.push_back(i+1);
				for(int j=0;j<=i;j++) {
					if(v[j] == 1)
						v[j] = 0;
					else
						v[j] = 1;
				}
				for(int j=0;j<(i+1)/2;j++) {
					int temp = v[j];
					v[j] = v[i-j];
					v[i-j] = temp;
				}
			}
		}
		if(v[0] != b[0])
			answer.push_back(1);
		cout<<answer.size()<<" ";
		for(auto x : answer)
			cout<<x<<" ";
		cout<<endl;
	}
	return 0;
}
