// Trie implementation in C++14

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pli pair<ll,int>
#define mp make_pair
using namespace std;
const unsigned ll l=1000000007;
const int MAX_=202;

class node
{
public:
  node* children[26];
  bool isEndofWord;
  int weight;

  node()
  {
    for(int i=0; i<26; i++)
      children[i] = nullptr;
    isEndofWord = false;
    weight = 0;
  }

};

void add(node* curr, string &s, int w)
{
  for(auto c: s)
  {
    curr->weight = max(curr->weight,w);
    if(curr->children[c-'a'] == nullptr)
      curr->children[c-'a'] = new node();
    curr = curr->children[c-'a'];
  }
  curr->isEndofWord = true;
  curr->weight = w;
}

void print(node* root, string s="")
{
  if(root->isEndofWord)
  {
    cout << s << endl;
  }
  for(int i=0; i<26; i++)
  {
    if(root->children[i] != nullptr)
    {
      print(root->children[i],s+char('a'+i));
    }
  }
}

int solve(node* root, string &s)
{
  for(auto c: s)
  {
    if(root->children[c-'a'] == nullptr)
      return -1;
    root = root->children[c-'a'];
  }
  return root->weight;
}

int main()
{
  int n,q;
  cin >> n >> q;

  node* root = new node();

  while(n--)
  {
    string s;
    cin >> s;
    int w;
    cin >> w;
    add(root,s,w);
  }
  while(q--)
  {
    string s;
    cin >> s;

    cout << solve(root,s) << endl;
  }


  return 0;
}

