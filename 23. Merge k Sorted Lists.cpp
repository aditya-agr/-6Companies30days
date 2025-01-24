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
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* temp = new ListNode(0);
        ListNode* root = temp;
        while(l1 && l2){
            if(l1->val < l2->val){
                temp->next = l1;
                l1 = l1->next;
            }
            else{
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if(l1) temp->next = l1;
        else temp->next = l2;
        return root->next;
    }
    ListNode* partition(int s, int e, vector<ListNode*> &lists){
        if(s==e)
            return lists[s];
        int mid = s+(e-s)/2;
        ListNode* l1 = partition(s, mid, lists);
        ListNode* l2 = partition(mid+1, e, lists);
        return merge(l1, l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(lists.empty())
            return NULL;
        return partition(0, n-1, lists);
    }
};