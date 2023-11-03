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
    pair<ListNode*,ListNode*> reverse(ListNode* start,ListNode* end)
    {
        ListNode* tail=start;
        ListNode* curr=start;
        ListNode* prev=NULL;
        ListNode* nextNode=NULL;
        while(curr!=NULL)
        {
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
            
        }
        
        return {prev,tail};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL)
            return NULL;
        
        ListNode* dhead=new ListNode(-1);
        dhead->next=head;
        ListNode* prev=dhead;
        
        ListNode* curr=head;
        int count=0;
        ListNode* start=NULL;
        while(curr!=NULL)
        {
            count++;
            if(count==1)
            {
                start=curr;
            }
            
            if(count==k)
            {
                ListNode* nextNode=curr->next;
                curr->next=NULL;
                auto p=reverse(start,curr);
                ListNode* front=p.first;
                ListNode* tail=p.second;
                
                prev->next=front;
                tail->next=nextNode;
                
                prev=tail;
                curr=tail;
                count=0;
            }
            curr=curr->next;
        }
        return dhead->next;
    }
};