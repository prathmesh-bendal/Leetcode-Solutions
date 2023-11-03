class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size();
        int m=nums2.size();
        
        if(n>m)
            return findMedianSortedArrays(nums2,nums1);
        
        
        int l=0,r=n;
        
        while(l<=r)
        {
            int n1=(l+r)/2;
            int n2=(n+m+1)/2-n1;
            
            int l1=INT_MIN,r1=INT_MIN;
            int l2=INT_MAX,r2=INT_MAX;
            
            if(n1-1>=0)
                l1=nums1[n1-1];
            if(n2-1>=0)
                r1=nums2[n2-1];
            
            if(n1<n)
                l2=nums1[n1];
            
            if(n2<m)
                r2=nums2[n2];
            
            if(l1<=r2 && r1<=l2)
            {
                if((n+m)%2==0)
                {
                    int lmax=max(l1,r1);
                    int rmin=min(l2,r2);
                    
                    return (lmax+rmin)/2.0000000;
                }
                else
                {
                    return max(l1,r1)*1.0000;
                }
            }
            
            if(l1>r2)
            {
                r=n1-1;
            }
            if(r1>l2)
            {
                l=n1+1;
            }
        }
        
        return -1.0000;
    }
};