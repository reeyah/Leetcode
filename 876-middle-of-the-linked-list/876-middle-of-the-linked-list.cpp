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
    ListNode* middleNode(ListNode* head) {
        int len = 0, i=0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            len++;
        }
        temp = head;
        while(temp){
            if(i==len/2)
                return temp;
            temp = temp->next;
            i++;
        }
        return NULL;
    }
};