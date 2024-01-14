class Solution {
    public String reverseWords(String s) {
        
        int flag=0;
        
        for(int i=0;i<s.length();i++)
        {
            if(s.charAt(i)!=' ')
                flag=1;
        }
        if(flag==0)
            return s;
        
        s=s.trim();
        
        
        List<String> list=new ArrayList<>();
        
        String curr="";
        
        for(int i=0;i<s.length();i++)
        {
            if(s.charAt(i)==' ')
            {
                if(curr.length()>0)
                list.add(curr);
                curr="";
            }
            else
            {
                curr+=s.charAt(i);
            }
        }
        
        if(curr.length()>0)
            list.add(curr);
        
//         for(int i=0;i<list.size();i++)
//         {
//             String word=list.get(i);
//             word=reverse(word);
//             list.set(i,word);
//         }
        
        String ans="";
        for(int i=list.size()-1;i>=0;i--)
        {
            ans+=list.get(i);
            if(i!=0)
            {
                ans+=" ";
            }
        }
        return ans;
        
        
    }
    
}