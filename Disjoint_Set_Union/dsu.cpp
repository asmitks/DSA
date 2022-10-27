#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
#define ld long double 
#define pr 998244353  
#define ff first
#define ss second
#define pb push_back
#define mp	make_pair
typedef vector<int> vi;
typedef pair<int, int> ii; 
typedef vector<ii> vii;
#define TR(c, it) for (auto it = (c).begin(); it != (c).end(); it++)
#define REP(i,a,b) for(int i=int(a);i<=int(b);i++)
#define MAXN 5000001
#define inf 1e9+500
 
//Templates
template <class T> ostream& operator << (ostream &os, const vector<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T> ostream& operator << (ostream &os, const set<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T, class S> ostream& operator << (ostream &os, const pair<T, S> &v) { os << v.first << ' ' << v.second; return os; }
template <class T, class S> ostream& operator << (ostream &os, const unordered_map<T, S> &v) { for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' '; return os; }

vector<int> pset(1000); // 1000 is just an initial number, it is user-adjustable.
void initSet(int _size) { pset.resize(_size); REP (i, 0, _size - 1) pset[i] = i; }
int findSet(int i) { return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); }
void unionSet(int i, int j) { pset[findSet(i)] = findSet(j); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

int main()
{
	// ifstream fin ('input.txt');
	// ofstream fout ('output.txt');
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	
	return 0;
}
