//Solution for problem https://codeforces.com/gym/226241/problem/C
#include<iostream>
using namespace std;
 
int main()
{
      char a[100];
      cin>>a;
      char chk[]="hello";
      int flag=0,prog=0;
      for(int j=0;j<5;j++)
      {
        for(;a[prog]!='\0';prog++)
        {
          if(a[prog]==chk[j])
          {
            flag++;
            prog++;
            break;
          }
        }
      }
      if(flag==5)
      {
          cout<<"YES";
      }
      else
      {
          cout<<"NO";
      }
      return 0;
}
