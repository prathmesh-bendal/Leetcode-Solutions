//{ Driver Code Starts
/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;
import java.math.*;

class GFG {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int t = Integer.parseInt(sc.next());
		while(t-- > 0)
		{
		    int n = Integer.parseInt(sc.next());
		    int k = Integer.parseInt(sc.next());
		    
		    String[] words = new String[n];
		    
		    for(int i=0;i<n;i++)
		    {
		        words[i] = sc.next();
		    }
		    
		    Solution ob = new Solution();
		  //  System.out.println(T.findOrder(words,k));
		    String order = ob.findOrder(words,n,k);
		    if(order.length() == 0){
		        System.out.println(0);
		        continue;
		    }
		    String temp[] = new String[n];
		    for(int i=0;i<n;i++)
		        temp[i] = words[i];
		    
		    Arrays.sort(temp, new Comparator<String>(){
		    
		      @Override
                public int compare(String a, String b) {
                    int index1 = 0;
                    int index2 = 0;
                    for(int i = 0; i < Math.min(a.length(), b.length()) 
                                        && index1 == index2; i++) {
                        index1 = order.indexOf(a.charAt(i));
                        index2 = order.indexOf(b.charAt(i));
                    }
                
                    if(index1 == index2 && a.length() != b.length()) 
                    {
                        if(a.length() < b.length())
                            return -1;
                        else
                            return 1;
                    }
                
                    if(index1 < index2)
                        return -1;
                    else
                        return 1;
                        
                }
		    });
		    
		    int flag = 1;
		    for(int i=0;i<n;i++)
		    {
		        if(!words[i].equals(temp[i]))
	            {
	                flag = 0;
	                break;
	            }
		    }
		    
		    System.out.println(flag);
		}
	}
	
}

// } Driver Code Ends


//User function Template for Java

class Solution
{
    public String findOrder(String [] words, int N, int K)
    {
        // Write your code here
        HashMap<Character,HashSet<Character>> adj=new HashMap<>();
        HashMap<Character,Integer> indegree=new HashMap<>();

        for(String s:words)
        {
            for(char c:s.toCharArray())
            {
                indegree.put(c,0);
            }
        }

        for(int i=0;i<words.length-1;i++)
        {
            String curr=words[i];
            String next=words[i+1];

            int len=Math.min(curr.length(),next.length());
            boolean flag=false;
            for(int j=0;j<len;j++)
            {
                char c1=curr.charAt(j);
                char c2=next.charAt(j);
                
                if(c1!=c2)
                {
                    HashSet<Character> s=new HashSet<>();
                    if(adj.containsKey(c1))
                    {
                        s=adj.get(c1);
                        if(s.contains(c2)==false)
                        {
                            s.add(c2);
                            indegree.put(c2,indegree.get(c2)+1);
                            adj.put(c1,s);
                        }

                    }
                    else
                    {
                        s.add(c2);
                        indegree.put(c2,indegree.get(c2)+1);
                        adj.put(c1,s);

                    }
                    flag=true;
                    break;
                }
            }
            if(flag==false && curr.length()>next.length())
            return "";
        }

        LinkedList<Character> q=new LinkedList<>();
        for(Character c:indegree.keySet())
        {
            if(indegree.get(c)==0)
            {
                q.addLast(c);
            }
        }

        StringBuilder sb=new StringBuilder();
        int count=0;
        while(!q.isEmpty())
        {
            char u=q.removeFirst();
            sb.append(u);
            count++;
            if(adj.containsKey(u))
            {
                HashSet< Character>nbrs = adj.get(u);
                for(char v:nbrs)
                {
                    indegree.put(v,indegree.get(v)-1);
                    if(indegree.get(v)==0)
                    {
                        q.addLast(v);
                    }
                }
            }
            
        }

        if(count==indegree.size())
        return sb.toString();

        return "";

        
        
    }
}