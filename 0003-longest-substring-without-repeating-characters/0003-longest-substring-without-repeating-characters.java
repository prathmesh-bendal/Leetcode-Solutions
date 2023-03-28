class Solution {
    public int lengthOfLongestSubstring(String s) {
        
        int ans=0;
        
        int i=0,j=0;
        
        HashMap<Character,Integer> mp=new HashMap<>();
        
        
        while(j<s.length())
        {
            char c=s.charAt(j);
            mp.put(c,mp.getOrDefault(c,0)+1);
            
            while(mp.get(c)>1)
            {
                char f=s.charAt(i);
                mp.put(f,mp.get(f)-1);
                i++;
            }
            
            ans=Math.max(ans,j-i+1);
            j++;
            
        }
        return ans;
        
    }
}