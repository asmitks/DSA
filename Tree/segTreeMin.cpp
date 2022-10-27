// Minimum Segment Tree implementation in C++14

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const unsigned ll l=1000000007;
const int MAX_=100005;


int tree[4*MAX_];
int a[MAX_];


void build(int node, int start, int end)
{
  if(start == end)
  {
    tree[node] = a[start];
    return;
  }

  int mid=(start+end)/2;

  build(2*node+1,start,mid);
  build(2*node+2,mid+1,end);

  tree[node] = min(tree[2*node+1],tree[2*node+2]);

}

int query(int node, int s, int e, int x, int y)
{
  if(x == s && y == e)
  {
      return tree[node];
  }
  int mid = (s+e)/2;

  if(x >= s && y <= mid)
    return query(node*2+1, s, mid, x, y);
  if(x >= mid+1 && y <= e)
    return query(node*2+2, mid+1, e, x, y);
  if(x >= s && y>= mid+1);
  {
    return min(query(node*2+1,s,mid,x,mid),query(2*node+2,mid+1,e,mid+1,y));
  }
}

void update(int node, int s, int e, int index, int val)
{
  if(s == e && s == index)
  {
    a[index] = val;
    tree[node] = val;
    return;
  }

  int mid = (s+e)/2;

  if(index >= s && index <= mid)
  {
    update(node*2+1,s,mid,index,val);
  }
  else if(index >= mid+1 && index <= e)
  {
    update(node*2+2,mid+1,e,index,val);
  }

  tree[node] = min(tree[2*node+1],tree[2*node+2]);
}


int main()
{
  int n,q;

  cin >> n >> q;

  for(int i=0; i<n; i++)
    cin >> a[i];

  build(0,0,n-1);

  while(q--)
  {
      char c;
      int x,y;
      cin >> c >> x >> y;

      if(c == 'q')
      {
          cout << query(0,0,n-1,x-1,y-1) << endl;
      }

      else if(c == 'u')
      {
        update(0,0,n-1,x-1,y);
      }

  }

  return 0;
}