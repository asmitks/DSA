// Heap implementation in C++17

#include<bits/stdc++.h>

using namespace std;

class Heap
{
  vector<int> items;
  public:
  Heap(vector<int>& v)
  {
    items = vector<int>(v);
    for(int i= items.size()/2-1; i>=0; i--)
    {
      heapifyDown(i);
    }
  }
  int parent(int i)
  {
    return (i-1)/2;
  }
  int left(int i)
  {
    return 2*i+1;
  }
  int right(int i)
  {
    return 2*i+2;
  }
  void heapifyDown(int i)
  {
    int largest = i;
    if(left(i) < items.size() && items[largest] < items[left(i)])
    {
      largest = left(i);
    }
    if(right(i) < items.size() && items[largest] < items[right(i)])
    {
      largest = right(i);
    }
    if(largest != i)
    {
      swap(items[i], items[largest]);
      heapifyDown(largest);
    }
  }
  void heapifyUp(int i)
  {
    while(i>0 && items[i] > items[parent(i)])
    {
    	swap(items[i], items[parent(i)]);
      	i = parent(i);
    }
  }
  void add(int item)
  {
    items.push_back(item);
    heapifyUp(items.size()-1);
  }
  int max()
  {
    return items.front();
  }
};

int main(){
  int num;
  cin >> num;                  // Reading input from STDIN
  vector<int> v;
  for(int i= 0; i<num; i++)
  {
    int n;
    cin >> n;
    v.push_back(n);
  }
  Heap heap(v);
  int q;
  cin >> q;
  while(q--)
  {
    int a,b;
    cin >> a;
    if(a == 1)
    {
      cin >> b;
      heap.add(b);
    }
    else
    {
      cout << heap.max() << endl;
    }
  }
  // printf("Input number is %d.\n", num);       // Writing output to STDOUT
  return 0;
}