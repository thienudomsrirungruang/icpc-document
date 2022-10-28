static class Node
{
	public int par = -1;
	public ArrayList<Integer> children;  
	public int depth = 0;
	public Node()
	{
		children = new ArrayList<Integer>();
	}
	public void add(int i)
	{
		children.add(i);
	}
	public void setPar(int i)
	{
		par = i;
		children.remove(Integer.valueOf(i));
	}
}