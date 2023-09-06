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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dhead=new ListNode(-1);
        
        ListNode* temp=dhead;
        int carry=0;
        while(l1!=NULL && l2!=NULL)
        {
            int sum=l1->val+l2->val+carry;
            carry=sum/10;
            
            ListNode* newNode=new ListNode(sum%10);
            temp->next=newNode;
            temp=temp->next;
            l1=l1->next;
            l2=l2->next;
        }
        
        while(l1!=NULL)
        {
            int sum=l1->val+carry;
            carry=sum/10;
            
            ListNode* newNode=new ListNode(sum%10);
            temp->next=newNode;
            temp=temp->next;
            l1=l1->next;
            
        }
        
        while(l2!=NULL)
        {
            int sum=l2->val+carry;
            carry=sum/10;
            
            ListNode* newNode=new ListNode(sum%10);
            temp->next=newNode;
            temp=temp->next;
            
            l2=l2->next;
        }
        
        if(carry>0)
        {
            ListNode* newNode=new ListNode(carry);
            temp->next=newNode;
        }
        return dhead->next;
    }
};