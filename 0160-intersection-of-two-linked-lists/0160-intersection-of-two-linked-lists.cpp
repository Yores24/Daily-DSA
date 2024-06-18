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
        int n1=1;
        int n2=1;
        ListNode* one=headA;
        ListNode* two=headB;
        while(one!=NULL){
            one=one->next;
            n1++;
        }
        while(two!=NULL){
            two=two->next;
            n2++;
        }
        int diff=0;
        if(n1>n2){
            diff=n1-n2;
            while(diff){
                headA=headA->next;
                diff--;
            }

        }
        else{
            diff=n2-n1;
            while(diff){
                headB=headB->next;
                diff--;
            }
        }
        one=headA;
        two=headB;
        while(one!=NULL && two!=NULL){
            if(one==two){
                return one;
            }
            one=one->next;
            two=two->next;
        }
        return NULL;
    }
};