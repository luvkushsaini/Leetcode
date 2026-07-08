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
    ListNode*mergeTwoLists(ListNode*p1,ListNode*p2){
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
            while(p1 && p2){
                if(p1->val<p2->val){
                    temp->next=p1;
                    p1=p1->next;
                    temp=temp->next;
                }
                else{
                    temp->next=p2;
                    temp=temp->next;
                    p2=p2->next;
                }
            }

            while(p1){
                    temp->next=p1;
                    temp=temp->next;
                    p1=p1->next;
                }
            while(p2){
                    temp->next=p2;
                    temp=temp->next;
                    p2=p2->next;
                }
            return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        ListNode*ans=NULL;
        for(int i=0;i<n;i++){
           ans=mergeTwoLists(lists[i],ans);
        }

        return ans;

    }
};