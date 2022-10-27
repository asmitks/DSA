class Node
{
	int data;
	Node left;
	Node right;

	Node(int val)
	{
		data=val;
		left=null;
		right=null;
	}
}

public class bst
{
	Node root;
	bst()
	{
		this.root=null;
	}

	private Node insert(int val, Node r)
	{
		if(r==null)
			r=new Node(val);
		else if(val<=r.data)
			r.left=insert(val,r.left);
		else
			r.right=insert(val,r.right);
		
		return r;
	}
	public void insert(int val)
	{
		this.root=insert(val,this.root);
	}

	public void preOrder()
	{
		preOrder(this.root);
	}
	private void preOrder(Node r)
	{
		if(r!=null)
		{
			System.out.print(r.data+" ");
			preOrder(r.left);
			preOrder(r.right);
		}
	}

	public void delete(int val)
	{
		this.root=delete(this.root,val);
	}
	private Node delete(Node r, int val)
	{
		if(r==null)
			return null;
		
		if(val<r.data)
			r.left=delete(r.left,val);
		else if(r.data<val)
			r.right=delete(r.right,val);
		else
		{
			if(r.left!=null && r.right!=null)
			{
				Node minRight=minNode(r.right);
				r.data=minRight.data;

				r.right=delete(r.right,minRight.data);
			}
			else if(r.left!=null)
				r=r.left;
			else if(r.right!=null)
				r=r.right;
			else
				r=null;
		}

		return r;
	}

	public Node minNode(Node r)
	{
		if(r.left==null)
			return r;
		else
			return minNode(r.left);
	}

	public static void main(String[] args) 
	{
		bst b=new bst();

		b.insert(3);
		b.insert(1);
		b.insert(2);
		b.insert(4);
		b.insert(5);


		System.out.println(b.root.data);
		System.out.println(b.root.left.data);
		System.out.println(b.root.left.right.data);
		System.out.println(b.root.right.data);
		System.out.println(b.root.right.right.data);


		b.delete(3);

		System.out.println();

		System.out.println(b.root.data);
		System.out.println(b.root.left.data);
		System.out.println(b.root.left.right.data);
		System.out.println(b.root.right.data);
		System.out.println(b.root.right.right.data);

	}
}