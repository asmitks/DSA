class Node
{
	Node[] children=new Node[26];
	boolean isLeaf;

	Node()
	{
		isLeaf=false;

		for(int i=0; i<26; i++)
			children[i]=null;
	}
}

class TrieADT
{
	Node root;

	TrieADT()
	{
		root=new Node();
	}

	private boolean isEmpty(Node root)
	{
		for(int i=0; i<26; i++)
			if(root.children[i]!=null)
				return false;
		return true;
	}

	void insert(String key)
	{
		key=key.toLowerCase();

		Node temp=root;
		int n=key.length();

		for(int i=0; i<n; i++)
		{
			int ind=key.charAt(i)-'a';

			if(temp.children[ind]==null)
				temp.children[ind]=new Node();

			temp=temp.children[ind];
		}

		temp.isLeaf=true;
	}

	boolean search(String key)
	{
		key=key.toLowerCase();
		int n=key.length();

		Node temp=root;

		for(int i=0; i<n; i++)
		{
			int ind=key.charAt(i)-'a';

			if(temp.children[ind]==null)
				return false;

			temp=temp.children[ind];
		}

		return temp.isLeaf;
	}

	private Node remove(String key, Node root, int level)
	{
		if(root==null)
			return null;

		if(level==key.length())
		{
			root.isLeaf=false;

			if(isEmpty(root))
				root=null;

			return root;
		}
		else
		{
			int ind=key.charAt(level)-'a';

			root.children[ind]=remove(key,root.children[ind],level+1);

			if(isEmpty(root) && !root.isLeaf)
				root=null;

			return root;
		}
	}

	void remove(String key)
	{
		remove(key.toLowerCase(),root,0);
	}

	void display()
	{
		display(this.root,"");
	}
	void display(Node root, String str)
	{
		if(root.isLeaf)
			System.out.println(str);

		for(int i=0; i<26; i++)
		{
			if(root.children[i]!=null)
			{
				String str1=str+(char)('a'+i);
				display(root.children[i],str1);
			}
		}
	}
}

class Main
{
	public static void main(String args[]) 
    { 

    	TrieADT tr=new TrieADT();

    	String[] keys = { "the", "a", "there", 
                      "answer", "any", "by", 
                      "bye", "their", "hero", "heroplane" }; 
    int n = keys.length; 
  
    // Construct trie 
    for (int i = 0; i < n; i++) 
        tr.insert(keys[i]); 
  
    // Search for different keys 
    //System.out.println(tr.search("the") ? "Yes\n" : "No\n"); 
    //System.out.println(tr.search("these") ? "Yes\n" : "No\n");  
  
    //tr.remove("hero"); 
    //System.out.println(tr.search("heroplane") ? "Yes\n" : "No\n"); 
      tr.display();   
    }
}