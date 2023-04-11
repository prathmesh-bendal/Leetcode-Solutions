class Solution {
    
    public boolean check(String a,String b,int [] position)
    {
        int i=0,j=0;
        while(i<a.length() && j<b.length())
        {
            if(a.charAt(i)==b.charAt(j))
            {
                i++;
                j++;
            }
            else
            {
                if(position[a.charAt(i)-'a']>position[b.charAt(j)-'a'])
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            
        }
        if(i<a.length())
            return false;
        
        return true;
    }
    public boolean isAlienSorted(String[] words, String order) {
        
        
        int [] position=new int[26];
        
        for(int i=0;i<order.length();i++)
        {
            position[order.charAt(i)-'a']=i;
        }
        
        for(int i=0;i<words.length-1;i++)
        {
            if(check(words[i],words[i+1],position)==false)
                return false;
        }
        return true;
    }
}