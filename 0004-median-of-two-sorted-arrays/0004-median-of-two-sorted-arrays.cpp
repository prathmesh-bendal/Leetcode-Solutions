class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size();
        int m=nums2.size();
        
        if(n>m)
            return findMedianSortedArrays(nums2,nums1);
        
        
        int left=0,right=n;
        
        while(left<=right)
        {
            int cut1=(left+right)/2;
            int cut2=(n+m)/2-cut1;
            
            int l1=INT_MIN,l2=INT_MIN;
            int r1=INT_MAX,r2=INT_MAX;
            
            if(cut1-1>=0)
                l1=nums1[cut1-1];
            
            if(cut2-1>=0)
                l2=nums2[cut2-1];
            
            if(cut1<n)
                r1=nums1[cut1];
            
            if(cut2<m)
                r2=nums2[cut2];
            
            if(l1<=r2 && l2<=r1)
            {
                int lc=max(l1,l2);
                int rc=min(r1,r2);
                
                if((n+m)%2==1)
                    return rc;
                
                return (lc+rc)/2.0000;
            }
            else if(l1>r2)
            {
                right=cut1-1;
            }
            else if(l2>r1)
            {
                left=cut1+1;
            }
        }
        return -1;
    }
};