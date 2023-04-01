class Solution {
    public String normalizeEmail(String email)
    {
        
        StringBuilder reduced=new StringBuilder();
        boolean flag=false;
        for(int i=0;i<email.length();i++)
        {
            char c=email.charAt(i);
            if(c=='@')
            {
                
                reduced.append(email.substring(i,email.length()));
                return reduced.toString();
            }
            else if(c=='+')
            {
                flag=true;
            }
            else if(flag==false)
            {
                if(c!='.')
                {
                    reduced.append(c);
                }
            }
        }
        
        return reduced.toString();
        
        
    }
    public int numUniqueEmails(String[] emails) {
        Map<String,Integer> mp=new HashMap<>();
        
        for(String email:emails)
        {
            String reduced=normalizeEmail(email);
            
            mp.put(reduced,mp.getOrDefault(reduced,0)+1);
        }
        
        return mp.size();
        
    }
}