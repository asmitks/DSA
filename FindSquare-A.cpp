//Solution for problem https://codeforces.com/contest/1028/problem/A
#include<iostream>
using namespace std;
 
int main()
{
  int n,m;
  cin>>n>>m;
  int flag=0,f_r,f_c;
  char a[n][m];
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<m;j++)
      {
          cin>>a[i][j];
          if(a[i][j]=='B'&&flag==0)
          {
            f_r=i;
            f_c=j;
            flag=1;
          }
      }
  }
  int i=f_r;
  int j=f_c;
  while(a[i][j]=='B')
  {
    i++;
    j++;
  }
  i--;
  j--;
  int r=(i+f_r)/2;
  int c=(j+f_c)/2;
  cout<<r+1<<" "<<c+1;
 
}
