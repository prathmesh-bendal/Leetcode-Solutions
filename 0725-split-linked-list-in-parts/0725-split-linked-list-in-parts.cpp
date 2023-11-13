/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            len++;
            temp=temp->next;
        }
        
        int size=len/k;
        int n=len%k;
        
        
        vector<ListNode*> ans(k);
        
        for(int i=0;i<k;i++)
        {
            int req=size;
            if(i<n)
                req=size+1;
            
            ListNode* dhead=new ListNode(-1);
            temp=dhead;
            int count=0;
            while(head!=NULL && count<req)
            {
                temp->next=head;
                head=head->next;
                temp=temp->next;
                count++;
            }
            temp->next=NULL;
            ans[i]=dhead->next;
        }
        return ans;
        
    }
};