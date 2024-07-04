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
    ListNode* mergeNodes(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return nullptr;
        ListNode* curr=new ListNode(0);
        ListNode*dum=curr;
        int sum=0;
        while(head){
            if(head->val==0){
                curr->next=new ListNode(sum);
                curr=curr->next;
                sum=0;
            }
            else{
                sum+=head->val;
            }
            head=head->next;
        }
        return dum->next->next;
    }
};