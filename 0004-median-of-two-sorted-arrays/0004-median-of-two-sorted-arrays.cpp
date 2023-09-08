class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size();
        int m=nums2.size();
        
        if(n>m)
            return findMedianSortedArrays(nums2,nums1);
        
        int count=n+m;
        int left=0,right=n;
        
        while(left<=right)
        {
            int cut1=(left+right)/2;
            int cut2=count/2-cut1;
            
            int l1=INT_MIN;
            if(cut1>0)
                l1=nums1[cut1-1];
            int r1=INT_MAX;
            if(cut1<n)
                r1=nums1[cut1];
            
            int l2=INT_MIN;
            if(cut2>0)
                l2=nums2[cut2-1];
            int r2=INT_MAX;
            if(cut2<m)
                r2=nums2[cut2];
            
            if(l1<=r2 && l2<=r1)
            {
                int op1=max(l1,l2);
                int op2=min(r1,r2);
                
                if(count%2==1)
                    return op2;
                
                return (op1+op2)/2.0000000;
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