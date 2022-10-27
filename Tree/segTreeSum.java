import java.util.*;

public class segTreeSum
{
	static int[] sum;
	static int[] a;

	static int constructTree(int l, int r, int ind)
	{
		if(l>r)
			return 0;
		if(l==r)
		{
			sum[ind]=a[l];
			return a[l];
		}
		else
		{
			int mid=(l+r)/2;

			int sumLeft=constructTree(l,mid,2*ind+1);

			int sumRight=constructTree(mid+1,r,2*ind+2);

			sum[ind]=sumLeft+sumRight;

			return sum[ind];
		}
	}

	static int getSumInRange(int ql, int qr, int curl, int curr, int ind)
	{
		if(ql<=curl && curr<=qr)
			return sum[ind];

		if(curl>qr || curr<ql)
			return 0;

		int mid=(curl+curr)/2;

		return getSumInRange(ql,qr, curl,mid, 2*ind+1) + getSumInRange(ql,qr, mid+1,curr, 2*ind+2);
	}

	static void update(int l, int r, int ind, int diff, int i)
	{
		if(i<l || i>r)
			return;

		sum[ind]+=diff;

		if(l!=r)
		{
			int mid=(l+r)/2;

			update(l,mid,2*ind+1,diff,i);
			update(mid+1,r,2*ind+2,diff,i);
		}
	}

	public static void main(String[] args) {
		a=new int[]{1,2,3,4,5,6};
		int n=6;

		int h=1+(int)Math.ceil(Math.log(n)/Math.log(2));
		int size=(int)Math.pow(2,h)-1;
		sum=new int[size];

		constructTree(0,n-1,0);

		for(int i=0; i<size; i++)
			System.out.print(sum[i]+" ");

		System.out.print("\n");

		System.out.println(getSumInRange(0,4,0,n-1,0));
		System.out.println(getSumInRange(1,4,0,n-1,0));
		System.out.println(getSumInRange(2,4,0,n-1,0));
		System.out.println(getSumInRange(3,4,0,n-1,0));

		update(0,n-1,0,2,2);

		
		for(int i=0; i<size; i++)
			System.out.print(sum[i]+" ");

		System.out.print("\n");



	}
}