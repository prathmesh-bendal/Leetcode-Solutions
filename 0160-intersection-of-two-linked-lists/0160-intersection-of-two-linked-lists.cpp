/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        set<ListNode*> seen;
        
        ListNode* temp=headA;
        
        while(temp!=NULL)
        {
            seen.insert(temp);
            temp=temp->next;
        }
        
        
        temp=headB;
        while(temp!=NULL)
        {
            if(seen.find(temp)!=seen.end())
                return temp;
            
            temp=temp->next;
        }
        return NULL;
        
    }
};