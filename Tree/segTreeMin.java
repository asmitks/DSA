import java.util.*;

public class segTreeMin
{
	static int[] mins;
	static int[] a;

	static int min(int a, int b)
	{
		return a<=b?a:b;
	}

	static int constructTree(int l, int r, int ind)
	{
		if(l>r)
			return 0;
		if(l==r)
		{
			mins[ind]=a[l];
			return a[l];
		}
		else
		{
			int mid=(l+r)/2;
			mins[ind]=min(constructTree(l,mid,2*ind+1),constructTree(mid+1,r,2*ind+2));
			return mins[ind];
		}
	}

	static int getMinInRange(int ql, int qr, int curl, int curr, int ind)
	{
		if(ql<=curl && curr<=qr)
			return mins[ind];

		if(curl>qr || curr<ql)
			return Integer.MAX_VALUE;

		int mid=(curl+curr)/2;

		return min(getMinInRange(ql,qr, curl,mid, 2*ind+1),getMinInRange(ql,qr, mid+1,curr, 2*ind+2));
	}

	static void update(int l, int r, int ind, int new_val, int i)
	{
		if(i<l || i>r)
			return;

		mins[ind]=min(new_val,mins[ind]);

		if(l!=r)
		{
			int mid=(l+r)/2;

			update(l,mid,2*ind+1,new_val,i);
			update(mid+1,r,2*ind+2,new_val,i);
		}
	}

	public static void main(String[] args) 
	{
		Scanner s=new Scanner(System.in);
		
		int n=s.nextInt();
		int m=s.nextInt();

		a=new int[n];

		for(int i=0; i<n; i++)
			a[i]=s.nextInt();

		int h=1+(int)Math.ceil(Math.log(n)/Math.log(2));
		int size=(int)Math.pow(2,h)-1;
		mins=new int[size];

		constructTree(0,n-1,0);

		for(int i=0; i<m; i++)
		{
			int l=s.nextInt();
			int r=s.nextInt();
			System.out.println(getMinInRange(l,r,0,n-1,0));
		}
	}
}