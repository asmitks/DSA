class heap
{
	static int[] h;
	static int n;


	static void insert(int val)
	{
		h[n++]=val;

		int i=n-1;

		while(i>0&& (h[i]<h[(i-1)/2]))
		{
			int temp=h[i];
			h[i]=h[(i-1)/2];
			h[(i-1)/2]=temp;

			i=(i-1)/2;
		}
	}

	static int extractMin()
	{
		if(n<=0)
			return -1;
		int res=h[0];
		h[0]=h[--n];

		heapify(0);

		return res;
	}

	static void heapify(int i)
	{
		while(i<(n+1)/2)
		{
			int min=i;
			if(2*i+1<n && h[i]>h[2*i+1])
				min=2*i+1;
			if(2*i+2<n && h[2*i+2]<h[min])
				min=2*i+2;

			if(min!=i)
			{
				int temp=h[min];
				h[min]=h[i];
				h[i]=temp;
			}
			else
				break;

			i++;
		}
	}

	public static void main(String[] args) {
		
		h=new int[10];

		/*insert(100);
		insert(10);
		insert(90);
		insert(20);
		insert(80);
		insert(30);
		insert(70);
		insert(40);
		insert(60);
		insert(50);*/

		h[0]=100;
		h[1]=10;
		h[2]=90;
		h[3]=20;
		h[4]=80;
		h[5]=30;
		h[6]=70;
		h[7]=40;
		h[8]=60;
		h[9]=50;

		n=10;
		heapify(0);

		for(int i=0; i<10; i++)
			System.out.print(h[i]+" ");

		System.out.println();

		for(int i=0; i<10; i++)
			System.out.print(extractMin()+" ");

	}
}